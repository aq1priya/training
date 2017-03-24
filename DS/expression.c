#include<stdio.h>
#include<stdlib.h>
#include<string.h>

srtuct node
{	char data;
	struct node *next;
};
 struct node *top = NULL;
void infix_to_postfix(char *);
struct node* create_node(int data);
int pop_node(struct node *top);
void push_node(char data);

void main()
{	char exp[50];
	printf("enter the expression\n");
	scanf("%s", exp);
	infix_to_postfix(exp);
}

void infix_to_postfix(char *exp)
{	int len, k=0;
	char operand;
	char infix[50] = NULL;
	char postfix[50] = NULL;
	strcpy(infix, exp);
	len = strlen(exp);
	for(i=0;i<len;i++)
	{	operand = infix[i];
		while (operand != '\0')
		{	if(operand >= 'a' && operand <= 'z' || operand >= 'A' && operand <= 'Z')
			{	postfix[k++]= operand;
			}
			else
			{	if(operand == '(')
			     	push_node(operand);
			     	else if( operand == '+' || operand == '-' || operand == '/' || operand == '*')
				      push_node(operand);
				     else if(operand == ')'	
			 	

int check_spaces(char ch)
{ if (ch == ' '|| ch == '\t')
	return 1;
 else
	continue ;
}

struct node* create_node(int data)
{	struct node *temp = (struct node *) malloc(sizeof (struct node));
        ptr->data = data;
        ptr->next = NULL;
}
void push_node(int data)
{	struct node *temp = create_node(data);
	if(top == NULL)
	{	top = temp;
		return;
	}
	else
	{	temp -> next = top;
		top = temp;
	}
}

int  pop_node(struct node *top)	
{	temp = top;
	if (top == NULL)
	printf("stack is empty\n");
	else
	{	top = top -> next;
		return(temp -> data);
		free(temp);
	}
}

	

