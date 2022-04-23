#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>

struct node
{
int data;
struct node *next;
}*head;

int search(int d)
{
    struct node *q;
    q=head;
    while(q!=NULL)
    {
        if(q->data==d)
        {
            printf("\n Give element found in the list");
            printf("\n Press any button to continue.....");
            getch();
            system("cls");
            return 0;
        }
        q=q->next;
    }
    printf("\n Element are not found!!!");
    printf("\n Press any button to continue.....");
    getch();
    system("cls");

}
void count()
{
    struct node *q;
    int cnt=0;
    q=head;
    while(q!=NULL)
    {
        q=q->next;
        cnt++;
    }
    printf("\n Count is %d",cnt);

    printf("\n Press any button to continue.....");
    getch();
    system("cls");
}
int reverse()
{
    struct node *p1,*p2,*p3;
    if(head->next==NULL)
    {
    return 0;
    }
    p1=head;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    p2->next=p1;

    while(p3!=NULL)
    {
         p1=p2;
         p2=p3;
         p3=p3->next;
         p2->next=p1;
    }
    head=p2;

    printf("\n Element are Reversed successfully ");
    printf("\n Press any button to continue.....");
    getch();
    system("cls");
}

int del(int d)
{
     struct node *tmp,*q;
      if(head->data==d)
      {
           tmp=head; head=head->next;
           free(tmp);
           return 0;

       }
       q=head;

    while(q->next->next!=NULL)
       {
           if(q->next->data==d)
           {
               tmp=q->next;
               q->next=tmp->next;
               free(tmp);
               return 0;
            }
            q=q->next;

        }
        if(q->next->data==d)
        {
             tmp=tmp->next;
             free(tmp);
             q->next=NULL;
             return 0;
        }
        printf("\n Element not found");

}

void add_at_beg(int d)
{
    struct node*tmp;
    tmp=malloc(sizeof(struct node));
    tmp->data=d;
    tmp->next=head;
    head=tmp;

    printf("\n Element are added successfully ");
    printf("\n Press any button to continue.....");
    getch();
    system("cls");
}

void add_after(int d,int pos)
{
     int i;
     struct node *tmp, *q;
     q=head;
     tmp=malloc(sizeof(struct node));
     tmp->data=d;
     for(i=0;i<pos-1;i++)
     {
         q=q->next;
     }
     tmp->next=q->next;
     q->next=tmp;

     printf("\n Element are added successfully ");
     printf("\n Press any button to continue.....");
     getch();
     system("cls");
}

void create(int v)
{
    struct node *tmp,*q;
    tmp=malloc(sizeof(struct node));
    tmp->data=v;
    tmp->next=NULL;
    if(head==NULL)
    {
        head=tmp;
    }
    else
    {
        q=head;
        while(q->next!=NULL)
        {
            q=q->next;

        }
        q->next=tmp;
    }
}

int display()
{
    struct node *q;
    if(head==NULL)
    {
        printf("\n List is empty");
        printf("\n Press any button to continue.....");
        getch();
        system("cls");
        return 0;
    }
    q=head;
    printf("\n The list is =");
    while(q!=NULL)
    {
        printf("\n %d",q->data);
        q=q->next;
    }
    printf("\n Press any button to continue.....");
    getch();
    system("cls");
}

void main()
{
    head=NULL;
    int ch,n,v,i,pos;
    while(1)
    {
        printf("\n 0) Exit \n 1) Create \n 2) Display \n 3) Add After \n 4) Add at begin \n 5) Delete \n 6) Reverse \n 7) Count \n 8) Search");
        printf("\n Enter your choice=");
        scanf("%d",&ch);

        switch(ch)
        {
            case 0:
                exit(0);
                break;
            case 1:
                system("cls");
                printf("\n How many nodes do you willing to create=");
                scanf("%d",&n);

                for(i=0;i<n;i++)
                {
                    printf("\n Enter the element=");
                    scanf("%d",&v);
                    create(v);
                }
                printf("\n Elements are added successfully ");
                printf("\n Press any button to continue.....");
                getch();
                system("cls");
                break;
            case 2:
                system("cls");
                display();
                break;
            case 3:
                system("cls");
                printf("\n Enter the position=");
                scanf("%d",&pos);
                printf("\n Enter the Element=");
                scanf("%d",&v);
                add_after(v,pos);
                break;
            case 4:
                system("cls");
                printf("\n Enter the element=");
                scanf("%d",&v);
                add_at_beg(v);
                break;

            case 5:
                system("cls");
                if(head==NULL)
                {
                    printf("\n List is EMPTY");
                    continue;
                }
                printf("\n Enter the element to delete=");
                scanf("%d",&v);
                del(v);
                printf("\n Element are Deleted successfully ");
                printf("\n Press any button to continue.....");
                getch();
                system("cls");
                break;
            case 6:
                system("cls");
                reverse();
                break;
            case 7:
                system("cls");
                count();
                break;
            case 8:
                system("cls");
                printf("\n Enter the element to search=");
                scanf("%d",&v);
                search(v);
                break;
        }
    }
}
