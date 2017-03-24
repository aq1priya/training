#include<stdio.h>
#include<stdlib.h>
struct node
{ 
	int info;
	struct node *nxt;
};
typedef struct node node;
node *top, *temp;
node *top = NULL;

void push();
void pop();
void display();
int count = 0;

void main()
{	int choice=1, val;
	printf("press 1 for push\n");
	printf("press 2 for pop\n");
	printf("press 3 for display\n");
	printf("press 0 for exit\n");
        while(choice!=0)
	{	printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{	case 1: printf("enter data\n");
				scanf("%d",&val);
				push(val);
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			default: printf("invalid input\n");
				 break;
				 return;
		}
	}
}

void push(int data)
{	if (top == NULL)
	{	top = (node *) malloc(sizeof(node));
		top -> nxt = NULL;
		top -> info = data;
	}
	else 
	{	temp = (node *) malloc(sizeof(node));
		temp->info = data;
		temp->nxt = top;
		top = temp;
	}
	count++;
}

void pop()
{	temp = top;
	if (temp == NULL)
	{	printf("invalid operation : stack is empty\n");
		return;
	}
	else 
	{	top = top -> nxt;
		printf("poped value : %d",temp -> info);
		free(temp);
		count--;
	}
}

void display()
{	temp = top;
	while(temp->nxt!=NULL)
	{
		printf("%d --->",temp->info);
		temp = temp -> nxt;
	}
	
	printf("%d", temp -> info);

}
		

	
	


