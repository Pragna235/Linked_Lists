#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head;

struct node* addToEmpty(struct node*head, int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
};

struct node* addAtBeg(struct node*head, int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
};

struct node * addAtEnd(struct node *head, int data)
{
    struct node* temp, *tp;
    temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    tp=head;
    while(tp->next!=NULL)
    {
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
};

struct node* addAfterPos(struct node*head, int data, int position)
{
    struct node*newP=NULL;
    struct node* temp=head;
    struct node*temp2=NULL;
    newP=addToEmpty(newP,data);
    while(position!=1)
    {
        temp=temp->next;
        position--;
    }
    if(temp->next==NULL)
    {
        temp->next=newP;
        newP->prev=temp;
    }
    else
    {
        temp2=temp->next;
        temp->next=newP;
        temp2->prev=newP;
        newP->next=temp2;
        newP->prev=temp;
    }
    return head;
};

struct node* addBeforePos(struct node *head, int data, int position)
{
    struct node*newP=NULL;
    struct node*temp=head;
    struct node*temp2=NULL;
    newP=addToEmpty(newP, data);
    int pos=position;
    while(pos>2)
    {
        temp=temp->next;
        pos--;
    }
    if(pos==1)
    {
        head=addAtBeg(head, data);
    }
    else
    {
        temp2=temp->next;
        temp->next=newP;
        temp2->prev=newP;
        newP->next=temp2;
        newP->prev=temp;
        return head;
    }
};

struct node* delFirst(struct node*head)
{
    struct node*temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;
    return head;
};

struct node* delLast(struct node*head)
{
    struct node* temp=head;
    struct node*temp2;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    return head;
};

struct node*delInter(struct node*head, int position)
{
    struct node*temp=head;
    struct node* temp2=NULL;
    if(position==1)
    {
        head=delFirst(head);
        return head;
    }
    while(position>1)
    {
        temp=temp->next;
        position--;
    }
    if(temp->next==NULL)
    {
        head=delLast(head);
    }
    else
    {
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
    }
    return head;
};

void create()
{
    head=0;
    int choice;
    struct node *temp, *newnode;
    printf("\nDo you want to continue? (Enter 0 for NO and 1 for YES) = ");
    scanf("%d",&choice);
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data = ");
        scanf("%d",&newnode->data);

        newnode->prev=0;newnode->next=0;

        if(head==0)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        printf("\nDo you want to continue? (Enter 0 for NO and 1 for YES) = ");
        scanf("%d",&choice);

    }
}

void display(struct node *head)
{
   struct node *ptr;
   ptr=head;
   while(ptr!=NULL)
   {
       printf("%d\t",ptr->data);
       ptr=ptr->next;

   }
}

int main()
{
    //Implementation of a Doubly Linked List
    create();



/*
    //Execution of addToEmpty()
    struct node*head=NULL;
    head=addToEmpty(head,45);
    printf("%d",head->data);
    return 0;
*/

/*
    //Execution of addAtBeg()
    struct node *head=NULL;
    struct node*ptr;
    head=addToEmpty(head,45);
    head=addAtBeg(head,34);
*/

/*
    //Execution of addAtEnd()
    struct node *head=NULL;
    struct node*ptr;
    head=addToEmpty(head,45);
    head=addAtBeg(head,34);
    head=addAtEnd(head,9);
*/

/*
    //Execution of addAfterPos()
    struct node *head=NULL;
    struct node*ptr;
    head=addToEmpty(head,45);
    head=addAtBeg(head,34);
    head=addAtEnd(head,9);

    head=addAfterPos(head, 5,2);
*/

/*
    //Execution of addBeforePos()
    struct node *head=NULL;
    struct node*ptr;
    head=addToEmpty(head,45);
    head=addAtBeg(head,34);
    head=addAtEnd(head,9);

    head=addBeforePos(head, 5,2);
*/

/*
    //Execution of delFirst()
    struct node *head=NULL;
    struct node*ptr;
    head=addToEmpty(head,45);
    head=addAtBeg(head,34);
    head=addAtEnd(head,9);

    head=delFirst(head);
*/

/*
    //Execution of delLast()
    struct node *head=NULL;
    struct node*ptr;
    head=addToEmpty(head,45);
    head=addAtBeg(head,34);
    head=addAtEnd(head,9);

    head=delLast(head);
*/

/*
    //Execution of delInter()
    struct node *head=NULL;
    struct node*ptr;
    head=addToEmpty(head,45);
    head=addAtBeg(head,34);
    head=addAtEnd(head,9);

    head=delInter(head,2);
*/

    display(head);
    return 0;
}
