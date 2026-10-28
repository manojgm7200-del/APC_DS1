#include<stdio.h>
#include<stdlib.h>
#include "main.h"

int insert_at_last(Dlist **head1, Dlist **tail1, int data1)
{
    Dlist *newNode = malloc(sizeof(Dlist));
    
    newNode->data=data1;
    newNode -> next = NULL;

    if(*head1 == NULL)
    {
        newNode -> prev = NULL;
        *head1 = newNode;
        return 0;
    }

    Dlist *temp = NULL;

    temp = *head1;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next= newNode;
    newNode -> prev = temp;
}

void print(Dlist *head1,Dlist *tail1,int data1)
{
    Dlist *temp;
    temp = head1;

    while(temp!=NULL)
    {
        printf("->%d ",temp->data);
        temp = temp-> next;

    }
    printf(" NULL\n");
}
int main(int argc, char *argv[])
{
    Dlist *head1,*head2,*tail1,*tail2;
    int data1,data2;
    if(argc >=4)

    {
        char *str=NULL;
        char *str1=NULL;

        str = argv[1];
        str1 = argv[3];

        int i=0;
        int j=0;

        if(argv[1][0] == '-' && argv[3][0] == '-')
        {
            str = argv[1]+1;
            str1 = argv[1]+1;

        }
        else
        {
            str = argv[1];
        }

        while(str[i]!=0)
        {
            data1 = str[i]-48;
            i++;

           insert_at_last(&head1,&tail1,data1); 
        }

        print(head1,tail1,data1);

        while(str1[j] != 0)
        {
            data2 = str1[j]-48;
            j++;
            insert_at_last(&head2,&tail2,data2);
        }
        print(head2,tail2,data2);

    }
    else
    {
        printf("Must give 4 Arguments\n");
    }
}