#include<stdio.h>
#include<stdlib.h>
#define size 100
int top=-1;
int stack[size];
int n;

int isfull()
{
	if(top==n-1)
		return 1;
	else
		return 0;
}

int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void push(int val)
{
	if(isfull())
		printf("\nOverflow");
	else
	{
		top++;
		stack[top]=val;
		printf("\n%d pushed",stack[top]);
	}
}

void pop()
{
	if(isempty())
		printf("\nUnderflow");
	else
	{
		printf("\n%d popped",stack[top]);
		stack[top]=-1;
		top--;
	}
}

void display()
{
	if(isempty())
		printf("\nEmpty Stack");
	else
	{	
		printf("\nElements are: ");
		for(int i=top;i>=0;i--)
			printf("\n%d",stack[i]);
		
	}
}

void findtop()
{
	printf("\ntop position=%d\ntop value=%d",top,stack[top]);
}

void main()
{
 
	int ch,entry;
	printf("enter the size of the stack");
        scanf("%d",&n);
	printf("enter size");
        scanf("%d",&n);
	while(1)
	{
		printf("\n\n1:PUSH\n2:POP\n3:DISPLAY\n4:Is Stack Empty\n5:Is Stack Full\n6:Find top\n7:Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter data");
				scanf("%d",&entry);
				push(entry);
				break;
			}
			
			case 2:
			{
				pop();
				break;
			}
			
			case 3:
			{
				display();
				break;
			}
			
			case 4:
			{
				if(isempty())
					printf("\nStack is Empty");
				else
					printf("\nStack is not Empty ");
				break;
			}
			
			case 5:
			{
				if(isfull())
					printf("\nStack is Full");
				else
					printf("\nStack is not Full ");
				break;
			}
			
			case 6:
			{
				findtop();
				break;
			}
			
			case 7:
			{
				printf("Exiting...");
				exit(0);
			}
			
			default:
			{
				printf("Invalid choice");
			}
		}
	}
}
