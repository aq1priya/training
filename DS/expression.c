#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{	char data;
	struct node *next;
};
struct node *top = NULL;
struct node *temp;

void infix_to_postfix(char *);
struct node* create_node (char data);
char pop_node(struct node *top);
void push_node(char data);

void main()
{	char exp[50];
	printf("enter the expression\n");
	scanf("%s", exp);
	infix_to_postfix(exp);
}

void infix_to_postfix(char *exp)
{	int len,i, k=0;
	char operand;
	char infix[50];
	char postfix[50];
	strcpy(infix, exp);
	len = strlen(exp);
	for(i=0;i<len;i++){
		operand = infix[i];
		
			if(operand >= 'a' && operand <= 'z' || operand >= 'A' && operand <= 'Z')
			postfix[k++]= operand;
			else{
			    if(operand == '(')
			    push_node(operand);
			    else{
				if( operand == '+' || operand == '-' || operand == '/' || operand == '*')
				push_node(operand);
				else{
				    if(operand == ')')
				    {   pop_node(top);
					 while (top != NULL)
					 {
					  if(top -> data != '('){
					  postfix[k++] = top -> data;
					  top = top -> next;}
					  else{
					  pop_node(top); 
					  top = top -> next;}
					  //pop_node(top);
					 // postfix[k++] = top -> data;}
					  //pop_node(top);}
					  break;
				    } 
				    }
				} 
			   }
			}
	}

printf("infix: %s \n", infix);
printf("postfix: %s \n", postfix);	 	
}


struct node* create_node(char data)
{	struct node *temp = (struct node *) malloc(sizeof (struct node));
        temp -> data = data;
        temp -> next = NULL;
}
void push_node(char data)
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

char  pop_node(struct node *top)	
{	temp = top;
	if (top == NULL)
	printf("stack is empty\n");
	else
	{	top = top -> next;
		return(temp -> data);
		free(temp);
	}
}

	

