#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
void add_at_pos(struct node* head, int data, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->link=NULL;
    pos--;
    while(pos!=1)
    {
        ptr=ptr->link;
        pos--;
    }
    ptr2->link=ptr->link;
    ptr->link=ptr2;
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
    add_at_pos(head, 23, 3);
    ptr=head;
    printf("\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}
