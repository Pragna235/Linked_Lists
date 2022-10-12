#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
void del_pos(struct node** head,int position)
{
    struct node* current=*head;
    struct node* previous=*head;

    if(*head==NULL)
    {
        printf("List is already empty!");
    }
    else if(position==1)
    {
        *head=current->link;
        free(current);
        current=NULL;
    }
    else
    {
        while(position!=1)
        {
            previous=current;
            current=current->link;
            position--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
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

    del_pos(&head,4);

    ptr=head;
    printf("\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}

