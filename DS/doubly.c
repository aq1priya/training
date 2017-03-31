#include<stdio.h>
#include<stdlib.h>

typedef struct linklist
{ 
int data;
struct linklist *prev;
struct linklist *next;
}node;
node *temp, *temp1;
node  *new;
node *head = NULL;
int count = 0;

void insert_front();
void insert_end();
void insert_loc();
void display();
void delet();

void main()
{	int choice=1;
	printf("press 1 to insert node at front\n");
        printf("press 2 to inser node at end\n");
	printf("press 3 to display\n");
	printf("press 4 to delet node\n");
	printf("press 5 to add node at given location\n");
	printf("press 0 to exit\n");
	while (choice != 0)
	{	printf("enter your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{	case 1: insert_front();
				break;
			case 2: insert_end();
				break;
			case 3: display();
				break;
			case 4: delet();
				break;
			case 5: insert_loc();
				break;
			default: printf("invalid input\n");
				break;
		}
	}
} 

void create()
{	int data;
	temp = (node *) malloc(sizeof(node));
	temp -> prev = NULL;
	temp -> next = NULL;
	printf("enter data to node\n");
	scanf("%d",&data);
	temp -> data = data;
	count++;
}

void insert_front()
{	if (head == NULL)
	{	printf("list is empty : create head node\n");
		create();
		head=temp;
	}
	else
	{	create();
		temp -> next = head;
		temp -> prev = NULL;
		head -> prev = temp;
		head = temp;
	}	
}

void insert_end()
{	temp1 = head;
	while( temp1 -> next != NULL)
	{	temp1 = temp1 -> next;
	}
	create();
	temp1 -> next = temp;
	temp -> prev = temp1;
	temp -> next = NULL;
}

void insert_loc()
{	int loc, i;
	node *q;
	printf("enter location:\n");
	scanf("%d",&loc );
	temp1 = head;
	for(i = 1;i < loc-1; i++)
	{	temp1 = temp1 -> next;
	} 
	create();
	q = temp1 -> next;
	temp1 -> next = temp;
	temp -> prev = temp1;
	temp -> next = q;
	q -> prev = temp;
}

void display()
{	temp = head;
	if(head == NULL)
	{	printf("list is empty\n");
	}
	else
	{	while(temp -> next != NULL)
		{	printf("%d<-->",temp -> data);
			temp = temp -> next;
		}
		printf("%d", temp ->data );
	}
}

void delet()
{	int num;
	temp = head;
	printf("enter data of node to be deleted\n");
	scanf("%d",& num);
	while(temp -> data != num)
	{	temp = temp -> next;
	}
	temp -> prev -> next = temp -> next;
	temp -> next -> prev = temp -> prev;
	free(temp);
}
