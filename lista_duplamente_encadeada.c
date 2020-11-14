#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node * next;
	struct node * prev;
} t_node;

void show_invert(t_node *list);
void show(t_node *list);
int append(t_node *list, int value); //success=1; faill=0
int pop(t_node *list); //success=1; faill=0
t_node * search(t_node *list, int key); //found=t_node; faill=NULL

int main(void) {
	t_node head, *includes; //head node
	head.next = NULL;
	head.prev = NULL;
	
	append(&head, 10);
	append(&head, 20);
	append(&head, 30);
	append(&head, 35);
	show(&head);
	show_invert(&head);

	includes = search(&head, 10);
	if(includes == NULL) printf("\nvalue is not in list.\n");
	else printf("\nsearch(%d): find *%d*\n", includes->value, includes->value);

	pop(&head);
	pop(&head);
	pop(&head);
	pop(&head);
	pop(&head);
	append(&head, 404);
	pop(&head);
	append(&head, 405);
	append(&head, 200);
	show(&head);

	includes = search(&head, 1000);
	if(includes == NULL) printf("\nvalue is not in list.\n");
	else printf("\nsearch(%d): *%d*\n", includes->value, includes->value);


}

t_node * search(t_node *list, int key)
{
	list->value = key;
	t_node *node = list->next;
		
	while(node->value != key) {
		node = node->next;
	} 
	
	if(node != list && node->value == key) return node;//node is not head and have the key=success else not found.

	return NULL;
}

int pop(t_node *list)
{
	t_node *last = list->prev, *new_last; 

	if(last == NULL) return 0; //Lista vazia
	
	new_last = last->prev;
	if(new_last == list) {
		new_last->prev = new_last->next = NULL;
		return 1;
	}

	list->prev = new_last;
	new_last->next = list;
	return 1;
}

int append(t_node *list, int value)
{
	t_node *new_node, *last_node; 

	new_node = (t_node *) malloc(sizeof(t_node));
	last_node = list->prev;

	if(!new_node) return 0; //memory allocation error
	
	new_node->value = value;
	
	if(last_node == NULL) {
		list->prev = list->next = new_node;
		new_node->next = new_node->prev = list;
		return 1;
	}

	last_node->next = new_node;
	new_node->prev = last_node;
	new_node->next = list;
	list->prev = new_node;
	return 1;
}


void show_invert(t_node *list)
{
	t_node *last_node = list->prev;
	if(last_node == NULL) {
		printf("[]\n");
		return;
	}

	printf("[ ");
	while(last_node != list) {
		printf("%d ", last_node->value);
		last_node = last_node->prev;
	}
	printf("]\n");
}

void show(t_node *list)
{
	t_node *node = list->next;
	if(node == NULL) {
		printf("[]\n");
		return;
	}
	printf("[ ");
	while(node != list) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("]\n");
}
