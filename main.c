#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "main.h"

Status print_list(Dlist *head);
Status insert_at_end(Node*list,int digit);
Status init(Node*list)
{
    list->head=NULL;
    list->tail=NULL;
}
Status create_list(Node *list,char*str)
{
    int i=0;
    int digit;
    while(str[i]!=0)
    {
        digit = str[i]-48;
        i++;
        insert_at_end(list,digit);
    }
}
Status print_list(Dlist*head)
{
        if(head==NULL)
        {
            printf("List is empty!!\n");
            return e_failure;

        }
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
Status insert_at_end(Node*list,int digit)
{
    Dlist*newNode=malloc(sizeof(Dlist));
    if(newNode == NULL)
    {
        printf("Memory allocation is failed\n");
        return e_success;
    }
    newNode->data=digit;
    newNode->next=NULL;

    if(list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        return e_success;
    }

    newNode -> prev = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;

    return e_success;
}

Status insert_at_first(Node*list,int digit)
{
    Dlist*newNode2= malloc(sizeof(Dlist));
    if(newNode2 == NULL)
    {
        printf("Memory allocation is failed\n");
        return e_success;
    }
    newNode2->data=digit;
    newNode2->prev=NULL;
    newNode2->next=NULL;

    if(list->head == NULL)
    {
        list->head = newNode2;
        list->tail = newNode2;

        return e_success;
    }

    newNode2->next = list->head;
    list->head->prev = newNode2;
    list->head = newNode2;

    return e_success;
}

Status addition(Node*list,Node*list2,Node*result)
{
    int digit;
    int sum=0,carry=0;

    Dlist*temp1=list->tail;
    Dlist*temp2=list2->tail;

    while(temp1 || temp2)
    {
        if(temp1 && temp2)
        {
            sum = temp1->data + temp2->data + carry;
            carry=sum/10;
            digit=sum%10;

            insert_at_first(result,digit);
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }

        else if(temp1 && (temp2==NULL))
        {
            sum = temp1->data + carry;
            carry=sum/10;
            digit=sum%10;

            insert_at_first(result,digit);
            temp1 = temp1->prev;
        }
        else if((temp1==NULL) && temp2 )
        {
            sum = temp2->data + carry;
            carry=sum/10;
            digit=sum%10;

            insert_at_first(result,digit);
            temp2 = temp2->prev;
        }
    }
    if(carry)
    {
        insert_at_first(result,carry);
        carry=0;
    }
    return e_success; 
}


int main(int argc,char *argv[])
{
    Node list;
    Node list2;
    Node result;

    init(&list);
    init(&list2);
    init(&result);

    create_list(&list,argv[1]);
    create_list(&list2,argv[3]);
    print_list(list.head);
    print_list(list2.head);
    addition(&list,&list2,&result);
    print_list(result.head);
}
