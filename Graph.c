#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root;

int create()
{
	struct node *tmp,*q;
	char ch1,ch2;
	char chance;
	root=malloc(sizeof(struct node));
	printf("\n Enter the root node value =");
	scanf("%d",&root->data);
	root->left=NULL;
	root->right=NULL;
	do
	{
		q=malloc(sizeof(struct node));
		printf("\n enter the node value=");
		scanf("%d",&q->data);
		q->left=NULL;
		q->right=NULL;
		tmp=root;
		do
		{
			printf("\n Left or right of %d=",tmp->data);
			scanf(" %c",&chance);

			if(chance=='l')
			{
				if(tmp->left==NULL)
				{
					tmp->left=q;
					break;
				}
				tmp=tmp->left;
			}
			else
			{
				if(tmp->right==NULL)
				{
					tmp->right=q;
					break;
				}
				tmp=tmp->right;
			}
		}while(1);

		printf("\n Do you want to add more nodes=");
		scanf(" %c",&ch1);
	}while(ch1=='y');
}

void dfs(struct node *head)
{
	if(head)
	{
		if(head->left)
		{
			dfs(head->left);
		}
		if(head->right)
		{
			dfs(head->right);
		}
	}
	printf("\t %d",head->data);
}

int main()
{
	system ("color 0a");
	int ch;
	char choice;
	root=NULL;
	do
	{
		printf("\n 0) Exit \n 1) Create \n 2) display=");
		printf("\n Enter your choice=");
		scanf("%d",&ch);
		switch(ch)
		{
		case 0:
			exit(0);
			break;
		case 1:
			create();
			break;
		case 2:
			dfs(root);
			break;
		}

		printf("\n Do you want to continue=");
		scanf(" %c",&choice);
	}while(choice=='y');

}
