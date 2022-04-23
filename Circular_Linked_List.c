#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>

struct  node
{
    int data;
    struct node*next;
}*head;

void create(int d)
{
    struct node *q, *tmp;
    tmp=malloc(sizeof(struct node));
    tmp->data=d;
    q=head;
    if(head==NULL)
    {
        head=tmp;
        tmp->next=tmp;
    }
    else
    {
        while(q->next!=head)
        {
            q=q->next;
        }
        q->next=tmp;
        tmp->next=head;
    }
}
int display()
{
    struct node*q;
    q=head;
    if(head==NULL)
    {
        printf("\n\nList is empty");
        return 0;
    }
    while(q->next!=head)
    {
        printf("%d->",q->data);
        q=q->next;
    }
    printf("%d",q->data);
}
void add_at_beg(int d)
{
    struct node *q,*tmp;
    tmp=malloc(sizeof(struct node));
    tmp->data=d;
    q=head->next;
    while(q->next!=head)
    {
        q=q->next;
    }
    tmp->next=head;
    q->next=tmp;
    head=tmp;
}
void add_after(int d, int pos)
{
    struct node *q,*tmp;
    int i;
    tmp=malloc(sizeof(struct node));
    tmp->data=d;
    q=head;
    for(i=0;i<pos-1;i++)
    {
        q=q->next;
    }
    tmp->next=q->next;
    q->next=tmp;
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

    while(p3!=head)
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
    fflush(stdin);
}

int del(int d)
{
    struct node *tmp,*q;
    q=head;
    tmp=head;
    if(head->data==d)
    {
        while(q->next!=head)
        {
            q=q->next;
        }
        head=head->next;
        q->next=head;
        free(tmp);
        return 0;
    }
    while(q->next->next!=head)
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
        tmp=q->next;
        q->next=head;
        free(tmp);
        return 0;
    }
    printf("\n Element not found");
}
void count()
{
    struct node *q;
    int cnt=0;
    q=head;
    do
    {
        q = q->next;
        cnt++;
    } while (q != head);

    printf("\n Count is %d",cnt);

    printf("\n Press any button to continue.....");
    getch();
    system("cls");
}
int search(int d)
{
    struct node *q;
    q=head;
    do
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
    }while(q!=head);

    printf("\n Element are not found!!!");
    printf("\n Press any button to continue.....");
    getch();
    system("cls");

}

void main()
{
	system ("color 0A");

    head=NULL;
    int ch,n,v,i,pos;
    while(1)
    {
        printf("\n 0) Exit \n 1) Create \n 2) Display \n 3) Add After \n 4) Add at begin \n 5) Delete \n 6)Reverse \n 7)Count \n 8)Search");
        printf("\n Enter your choice=");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("\n How many nodes do you willing to create=");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("\n Enter the element=");
                scanf("%d",&v);
                create(v);
            }
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\n Enter the position=");
            scanf("%d",&pos);
            printf("\n Enter the Element=");
            scanf("%d",&v);
            add_after(v,pos);
            break;
        case 4:
            printf("\n Enter the element=");
            scanf("%d",&v);
            add_at_beg(v);
            break;
        case 5:
            if(head==NULL)
            {
                printf("\n List is EMPTY");
                continue;
            }
            printf("\n Enter the element to delete=");
            scanf("%d",&v);
            del(v);
            break;
        case 6:
            reverse();
            break;
        case 7:
            count();
            break;
        case 8:
            printf("\n Enter the element to search=");
            scanf("%d",&v);
            search(v);
            break;
        }
    }
}
