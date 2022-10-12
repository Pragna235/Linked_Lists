#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* del_first(struct node* head)
{
    if(head==NULL)
    {
        printf("List is already empty!");
    }
    else
    {
        struct node *temp=head;
        head=head->link;
        free(temp);
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

    head=del_first(head);

    ptr=head;
    printf("\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}
