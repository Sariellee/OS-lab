#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void print_list(struct Node* list){
	if(list -> next == NULL){
		printf("EMPTY");
	}
	else{
		struct Node *node = list -> next;
		while(node != NULL){
		 	printf("%d ", node -> data);
			node = node -> next;
		}
	}
	printf("\n");
}

void insert_node(struct Node* list, int data){
	if(list -> next == NULL){
		list -> next = (struct Node*)malloc(sizeof(struct Node));
		list -> next -> next = NULL;
		list -> next -> data = data;
	}
	else{
		struct Node *node = list -> next;
		while(node -> next != NULL){
		 	//printf("%d ", node -> data);
			node = node -> next;
		}
		node -> next = (struct Node*)malloc(sizeof(struct Node));
		node -> next -> next = NULL;
		node -> next -> data = data;
	}

}

void delete_node(struct Node* list, int index){ // deleting by index
	if(index == 0 && list -> next -> next == NULL){
		struct Node *del = list -> next;
		list -> next = NULL;
		free(del);
		return;
	}
	if(index == 0){
		struct Node *del = (list -> next);
		*list = *(list -> next);
		free(del);
		return;
	}
	struct Node *tempNode = list -> next;
	for(int i = 0; i < index-1; i++){
		tempNode = tempNode -> next;
	}
	struct Node *del = (tempNode -> next);
	if(tempNode -> next -> next != NULL){
		tempNode -> next = tempNode -> next -> next;
	}
	else{
		tempNode -> next = NULL;
	}

	free(del); 

}

int main(){
	struct Node *list = malloc(sizeof(struct Node));
	list -> data = NULL;
	list -> next = NULL;

	print_list(list);

	insert_node(list, 1);
	print_list(list);

	insert_node(list, 3);
	print_list(list);

	insert_node(list, 5);
	insert_node(list, 2);
	print_list(list);

	delete_node(list, 3);
	print_list(list);

	delete_node(list, 1);
	print_list(list);

	delete_node(list, 0);
	print_list(list);

	delete_node(list, 0);
	print_list(list);
}
