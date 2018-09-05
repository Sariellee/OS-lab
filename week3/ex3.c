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

void insert_node(struct Node** list, int data){
	list[0] = list[0] -> next;
	if((*list) == NULL){
		(*list) = (struct Node*)malloc(sizeof(struct Node));
		(*list) -> next = NULL;
		(*list) -> data = data;
	}
	else{
		struct Node *node = list;
		while(node -> next != NULL){
		 	//printf("%d ", node -> data);
			node = node -> next;
		}

		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		node -> next = newNode;
		newNode -> data = data;
		newNode -> next = NULL;
	}
}

void delete_node(struct Node* list, int index){ // deleting by index
	if((list -> next) -> next == NULL){
		printf("here ");
		
		list -> next = NULL;
		//free(list);
		return;
	}

	list = list -> next;
	if(index == 0){
		struct Node *delPointer = list;
		(*list) = *(list -> next);
		//free(delPointer);
		delPointer = NULL;
		return;
	}

	struct Node *tempNode = list;
	for(int i = 0; i < index-1; i++){
		tempNode = tempNode -> next;
	}

	struct Node *delPointer = tempNode -> next;

	if((tempNode -> next) -> next != NULL){
		tempNode -> next = (tempNode -> next) -> next;
	}
	else{
		tempNode -> next = NULL;
	}
	free(delPointer);
}

int main(){
	struct Node *list = malloc(sizeof(struct Node));
	list -> data = NULL;
	list -> next = malloc(sizeof(struct Node));

	print_list(list);

	insert_node(&list, 1);
	print_list(list);

	insert_node(&list, 3);
	print_list(list);

	insert_node(&list, 5);
	insert_node(&list, 2);
	print_list(list);

	delete_node(list, 0);
	print_list(list);

	delete_node(list, 1);
	print_list(list);

	delete_node(list, 0);
	print_list(list);

	delete_node(list, 0);
	print_list(list);

	printf("%d", list==NULL);

}