#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* insert_at_beg(struct node*head, int data);
int main()
{

    struct node *head= malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=98;
    ptr->link=NULL;
    head->link=ptr;
    int data = 3;


    //struct node *ptr=NULL;
    ptr=head;
    printf("Before inserting!\n");
    while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    head=insert_at_beg(head,data);
        ptr=head;
    printf("After inserting!\n");
    while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }




    return 0;


}



struct node* insert_at_beg(struct node*head, int data)
{


    struct node*ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    ptr->link=head;
    head=ptr;
    return head;


}
