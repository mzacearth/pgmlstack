#include <stdio.h>
#include <stdlib.h>

//New node creation with data and next pointer
struct node {
	int data;
	struct node *next;
};
struct node *top = NULL;

// push() operation on a  stack
void push(int value) {
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = value;
	if (top == NULL) {
		newnode->next = NULL;
	}
	else {
		newnode->next = top;		 // Make the node as top
	}
	top = newnode; 				// top always points to the newly created node
	printf("Value Inserted\n");
}

// pop() operation on a  stack
int pop() {
	
		struct node *del = top;
		int del_data = top->data;
		top = top->next;
		free(del);
		return del_data;
}

void display() {
	if (top == NULL) {
		printf("\nEmpty Stack\n");
	} else {
		printf("The stack is \n");
		struct node *pos= top;
		printf("%d<--top\n", pos->data);
		pos= pos->next;
		while (pos->next != NULL) {
			printf("%d\n", pos->data);
			pos= pos->next;
		}
		printf("%d\n\n", pos->data);
	}
}

int main() {
	int choice, value;
	printf("\nImplementaion of Stack using Linked List\n");
	while (1) {
		printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("\nYour choice : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\nEnter the value to push: ");
			scanf("%d", &value);
			push(value);
			break;
		case 2:
			if (top == NULL) {
				printf("\nStack Underflow\n");
			} 
			else {
				printf("Successfully popped.");
				printf("Popped element is :%d\n", pop());
			}
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Farewell...\n");
			exit(0);
			break;
		default:
			printf("\nWrong Choice\n");
		}
	}
}

