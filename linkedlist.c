#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
int main()
{
    struct node *head, *ptr,*newnode;
    head=0;
    int n=0;
    while(n<5)
    {

        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nnewnode = %d\n",newnode);
        printf("Enter an integer = ");
        scanf("%d",&newnode->data);
        printf("newnode->data =  %d\n",newnode->data);

        printf("Value stored in present new node is %d",newnode->data);
        newnode->link=0;
        printf("\nnewnode->link =  %d",newnode->link);
        if(head==0)
        {
            head=ptr=newnode;
            printf("\nValue in head = %d\n",head);
        }
        else
        {
            ptr->link=newnode;
            printf("\n ptr->link = %d\n",ptr->link);
            ptr=newnode;
            printf("\n ptr = %d\n",ptr);
        }


        n++;
        printf("\n");



    }
    ptr=head;
    printf("\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}
