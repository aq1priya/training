#include<stdio.h>
#include<stdlib.h>

struct link
{	int data;
	struct link *next;
};
typedef struct link  node;
node *front = NULL, *rear = NULL, *temp;

void insert(int a);
void delet();
void display();

void main()
{	int choice = 1, val, info;
	printf("press 1 to start or press 0 to exit\n");
	scanf("%d", &choice);
	printf("press 1 for inserting\n");
	printf("press 2 for deleting\n");
	printf("press 3 for display\n");
	while (choice != 0)
	{	printf("enter your choice\n ");
		scanf("%d",&choice );
		switch (choice)
		{	case 1: printf("enter data\n");
				scanf("%d", &info);
				insert(info);
				break;
			case 2: delet();
				break;
			case 3: display();
				break;
			default: printf(" invalid input\n");
				break;
		}
	}
}

void insert(int a)
{	if(rear == NULL)
	{	rear = (node *) malloc(sizeof(node));
		rear -> next = NULL;
		rear -> data = a;
		front = rear;
	}
	else
	{	temp = (node *) malloc(sizeof(node));
		temp -> data = a;
		temp -> next = NULL;
		rear -> next = temp;
		rear = temp;
	}
}

void delet()
{
	if(front == NULL)
	{	printf("queue is empty\n");
		return;
	}
	else
	{	temp = front;
		printf("data of deleted item: %d", temp -> data);
		front = temp -> next;
		free(temp);
		
	}
}

void display()
{	if (front == NULL || rear == NULL)
	{	printf("nothing to display: Queue is empty\n");
	}
	else
	{	temp = front;
		while(temp -> next != NULL)
		{	printf("%d--->",temp -> data);
			temp = temp -> next;
		}
		printf("%d\n",temp -> data);
	}
}
		
 

			
