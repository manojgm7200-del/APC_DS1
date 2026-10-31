#ifndef HEAD_H
#define HEAD_H

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;


}Dlist;

typedef enum
{
    e_success,
    e_failure
}Status;

typedef struct
{
   Dlist *head;
   Dlist *tail;
}Node;
#endif
