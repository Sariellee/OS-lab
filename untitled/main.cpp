#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int p_awake = 0;
int c_awake = 0;

int bufSize = 10; // buffer size

int n = 0; // filled spots in buffer

int* buf;


void *producer(pthread_t* id){
    while(p_awake){
        while(n!=10){
            buf[n] = 1;
            n++;
            c_awake = 1; // or after loop?
            for (int i = 0; i < n; ++i){
                printf("%d", buf[i]);
            }
        }
        p_awake = 0;
    }
    pthread_exit(id);
}

void *consumer(pthread_t* id){
    while(c_awake){
        while(n!=0){
            buf[n] = 0;
            n--;
            p_awake = 1;
            for (int i = 0; i < n; ++i){
                printf("%d", buf[i]);
            }
        }
        c_awake = 0;
    }
    pthread_exit(id);
}

int main(){
    buf = (malloc(sizeof(int) * bufSize));
    for(int i = 0; i < n; i++){
        buf[i] = 0;
    }
    pthread_t p, c;
    pthread_create(&p, NULL, (void*) producer, p);
    pthread_create(&c, NULL, (void*) consumer, c);
}