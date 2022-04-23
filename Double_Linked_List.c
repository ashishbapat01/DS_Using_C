#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>

void clear()
{
    printf("\n Press any button to continue.....");
    getch();
    system("cls");
}

struct node
{
     int data;
     struct node*next;
     struct node *prev;
}*head;

void add_after(int d,int pos)
{
    struct node*q, *tmp;
    int i;
    q=head;
    for(i=0;i<pos-1;i++)
    {
         q=q->next;
    }
    tmp=malloc(sizeof(struct node));
    tmp->data=d;
    q->next->prev=tmp;
    tmp->next=q->next;
    tmp->prev=q;
    q->next=tmp;
    printf("\n Number added successfully");
    clear();
}

void add_at_beg(int d)
{
     struct node *tmp;
     tmp=malloc(sizeof(struct node));
     tmp->data=d;
     tmp->prev=NULL;
     tmp->next=head;
     head->prev=tmp;
     head=tmp;
     printf("\n Number added successfully");
     clear();
}
int delete(int d)
{
    struct node *tmp,*q;
    if(head->data==d)
    {
        tmp = head;
        head=head->next;
        head->prev=NULL;
        free(tmp);
        return 0;
    }
    q=head;
    while(q->next->next!=NULL)
    {
        if (q->next->data==d)
        {
            tmp = q->next;
            q->next=tmp->next;
            tmp->next->prev=q;
            free(tmp);
            return 0;
        }
        q=q->next;
    }
    if(q->next->data==d)
    {
        tmp=q->next;
        free(tmp);
        q->next=NULL;
        return 0;
    }
    printf("\n Element not found");
}

void reverse()
{
    struct node *p1,*p2;
    p1=head;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;

    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    head=p1;

    printf("\n List Are Reversed");
    clear();
}

void count()
{
    int cnt = 0,i;
    struct node* q;
    q=head;
    if(head==NULL)
    {
        exit(0);
    }

    while(q!=NULL)
    {
        cnt ++;
        q=q->next;
    }
    printf("\n Count is = %d",cnt);
    clear();

}
int search(int d)
{
    struct node *q;
    q=head;

    while (q!=NULL)
   {
       if(q->data==d)
       {
           printf("\n Element found ");
           return 0;
       }
       q=q->next;
    }
    printf("\n Element Not Found");
}
void create (int d)
{
    struct node* q,*tmp;
    tmp=malloc(sizeof(struct node));
    tmp->data=d;
    tmp->next=NULL;
    tmp->prev=NULL;
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
        tmp->prev=q;
    }
}

void display()
{
    struct node *q;
    q=head;
    while(q!=NULL)
    {
        printf("%d->",q->data);
        q=q->next;
    }
    clear();
}

void main()
{
	    system("color 0a");
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
                printf("\n How many nodes do you willing to create=");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("\n Enter the element=");
                    scanf("%d",&v);
                    create(v);
                }
                printf("\n List Created Successfully");
                clear();
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
                delete(v);
                clear();
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
                clear();
                break;
            }
     }
}

