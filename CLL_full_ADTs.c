#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail;

void createCLL()
{
    struct node *newnode, *temp;
    int choice = 1;
    tail=0;

    while(choice)
    {
        struct node* newnode=malloc(sizeof(struct node));
        printf("Enter data = ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Do you want to continue? = ");
        scanf("%d", &choice);
    }
}
void print(struct node*tail)
{
    struct node* p;
    if(tail==0)
        printf("List is empty!");
    else
    {
        p=tail->next;

        do
        {
            printf("%d\t",p->data);
            p=p->next;
        }while(p!=tail->next);
        printf("\n");
    }

}

struct node* addToEmpty(int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node* addAtBeg(struct node* tail,int data)
{
    struct node* newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=tail->next;
    tail->next=newP;
    return tail;
}

struct node* addAtEnd(struct node* tail, int data)
{
    struct node* newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=tail->next;
    tail->next=newP;
    tail=tail->next;
    return tail;
};

struct node* addAfterPos(struct node* tail, int data, int pos)
{
    struct node *p=tail->next;
    struct node* newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=NULL;

    while(pos>1)
    {
        p=p->next;
        pos--;
    }
    newP->next=p->next;
    p->next=newP;
    if(p==tail)
    {
        tail=tail->next;
    }
    return tail;
};

struct node* delFirst(struct node*tail)
{
    if(tail==NULL)
    {
        return tail;
    }
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    struct node*temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    return tail;
};

struct node* delLast(struct node* tail)
{
    if(tail==NULL)
        return tail;
    struct node*temp=tail->next;
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
};

struct node* delInter(struct node* tail, int pos)
{
    if(tail==NULL)
        return tail;
    struct node* temp=tail->next;
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    while(pos>2)
    {
        temp=temp->next;
        pos--;
    }
    struct node* temp2=temp->next;
    temp->next=temp2->next;
    if(temp2==tail)
    {
        tail=temp;
    }
    free(temp2);
    temp2=NULL;
    return tail;
};

int main()
{
    //createCLL();
    tail=addToEmpty(23);
    tail=addAtBeg(tail,45);
    tail=addAtBeg(tail,34);
    tail=addAtEnd(tail,56);
    tail=addAfterPos(tail,4,2);
    print(tail);

    tail=delFirst(tail);
    print(tail);

    tail=delLast(tail);
    print(tail);

    tail=delInter(tail,2);
    print(tail);
    return 0;
}
