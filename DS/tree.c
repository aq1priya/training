#include<stdio.h>
#include<stdlib.h>

struct tree_node
{	int data;
	struct tree_node *left;
	struct tree_node *right;
};
typedef struct tree_node node;
node *current, *temp, *root = NULL;

int insert();
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
void find(node *root);
int min(node *root);
int max(node *root);

void main()
{	int choice = 1,  a;
	printf("press 1 to insert node\n");
	printf("press 2 to display tree in preorder\n");
	printf("press 3 to display tree in inorder\n ");
	printf("press 4 to display tree in postorder\n");
	printf("press 5 to find an element\n");
	printf("press 6 to find minimum node");
	printf("press 7 to find maximum value");
	while(choice != 0)
	{	printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{	case 1: insert(a);
				break;
			case 2: printf("display : pre-order\n");
				preorder(root);
				break;
			case 3: printf("display : inorder\n");
				inorder(root);
				break;
			case 4: printf("display : post-order\n");
				postorder(root);
				break;
			case 5: //printf("enter node value to be find\n ");
				//scanf("%d",&a);
				find(root);
				break;
			case 6: min(root);
				break;
			case 7: max(root);
				break;
			default:printf("invalid input");
				 break;
		}
	}
}
	
int insert()
{	int val;
	printf("enter data\n");
	scanf("%d",&val);

	temp = (node *) malloc(sizeof(node));
	temp -> data = val;
	temp -> left = NULL;
	temp -> right = NULL;
	if(root == NULL)
	{	root = temp;
	}
	else
	{	current = root;
		while(current != NULL)
		{	if(val < current->data)
			{	if(current->left == NULL)
				{	current -> left = temp;
					break;
				} 
				else
				{	current = current -> left;
				}
			}
			else if (val > current->data)
			{	if(current -> right == NULL)
				{	current -> right = temp;
					return 1;	
				}
				else
				{	current = current -> right;
				}
			}
		}
	}
}

void preorder(node *root) 
{	if(root != NULL) 
	{	printf("%d ",root->data);
      		preorder(root->left);
      		preorder(root->right);
   	}
}

void inorder( node *root) 
{	if(root != NULL) 
	{	inorder(root->left);
     		printf("%d ",root->data);          
      		inorder(root->right);
   	}
}

void postorder(node *root)
{	if(root != NULL) 
	{	postorder(root->left);
      		postorder(root->right);
      		printf("%d ", root->data);
  	}
}
	
void find( node *root)
{	int no, i=1;
	printf("enter node value to find\n");
	scanf("%d",&no);
	while(root -> data != no)
	{	if (no < root -> data)
		{	find(root -> left);
		}
		else
		{	find(root -> right);
		}
	}
	if(root -> data == no)
		printf("[%d]", root -> data);
	else
		printf("NULL\n");
	//
//	if(root != NULL)
//	{	
//			if(no == root -> data)
//			{	printf("[%d]",root -> data);
//			}
//			find(root -> left);
//			find(root -> right);
//	}
}

int min(node *root)
{	temp = root;
  	while (temp->left != NULL) 
	{	temp = temp -> left;
  	}
  	return(temp -> data);
}

int max(node *root)
{	temp = root;
	while(temp -> right != NULL)
	{	temp = temp -> right;
	}
	return(temp -> data);
}
