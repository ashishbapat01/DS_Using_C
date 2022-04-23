#include<stdio.h>
#include<stdlib.h>

int q[10],front=0,rear=0;
int add(int d)
{
    if(rear==10)
    {
        printf("\nQueue is full");
        return 0;
    }
    q[rear]=d;
    rear++;
}
int display()
{
    int i;
    if(front==rear)
    {
        printf("\n Queue is empty");
        return 0;
    }
    for(i=front;i<rear;i++)
    {
        printf("\n%d",q[i]);
    }
}
int delete ()
{
    if(front==rear)
    {
        printf("\n\nQueue is empty ");
        return 0;
    }
    front++;
}

int main()
{

    int d,i,ch,n;
    while(1)
        {
            printf("\n 0) Exit");
            printf("\n 1) Add");
            printf("\n 2) Delete");
            printf("\n 3) Display");
            printf("\n Enter your choice =");
            scanf("%d",&ch);
            switch(ch)
            {
            case 0:
                exit(0);
                break;
            case 1:
                printf("\n How many elememts you want to add =");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                printf("\n Enter the element=");
                scanf("%d",&d);
                add(d);
                }
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
        }
    }
}
