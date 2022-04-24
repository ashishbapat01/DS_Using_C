#include <stdio.h>
#include <stdlib.h>

int stack[10],top=0;


int push(int d)
{
    if(top==9)
    {
        printf("\nStack is full");
        return 0;
    }
    stack[top]=d;
    top++;
}

int display()
{
    int i;
    if(top==0)
        {
            printf("\n List is empty");
            return 0;
        }
        for(i=0;i<top;i++)
        {
            printf("\n%d",stack[i]);
        }
}

int pop()
{
    if(top==0)
    {
         printf("\nList is empty");
         return 0;
    }
    top = top - 1;
}

int main()
{
    int d,i,ch,n;
    while(1)
    {
        printf("\n 0) Exit");
        printf("\n 1) Push");
        printf("\n 2) Pop");
        printf("\n 3) Display");
        printf("\n Enter your choice =");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                exit(0);
                break;
            case 1:
                printf("\n How many elememts you want to push =");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                printf("\n Enter the element=");
                scanf("%d",&d);
                push(d);
                }
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    }
}


