#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* del_last(struct node* head)
{
    if(head==NULL)
    {
        printf("List is already empty!");
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp=head;
        struct node *temp2=head;
        while(temp->link!=NULL)
        {
            temp2=temp;
            temp=temp->link;
        }
        temp2->link=NULL;
        free(temp);
        temp=NULL;
    }
    return head;
}
int main()
{
    struct node *head, *ptr,*newnode;
    head=0;
    int n=0;
    while(n<5)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter an integer = ");
        scanf("%d",&newnode->data);

        newnode->link=0;

        if(head==0)
        {
            head=ptr=newnode;

        }
        else
        {
            ptr->link=newnode;
            ptr=newnode;

        }
        n++;
     }

    head=del_last(head);

    ptr=head;
    printf("\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}
