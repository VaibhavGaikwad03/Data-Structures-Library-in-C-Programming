#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

void Display(PNODE Head)
{
    printf("Data from the queue is : \n");

    while(Head != NULL)
    {
        printf("|%d|->",Head->data);
        Head = Head->next;
    }
    printf("\n");
}

void Enqueue(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next =  NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {   
        PNODE temp = *Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Dequeue(PPNODE Head)
{
    int value = 0;

    if(*Head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    PNODE temp = *Head;
    value = temp->data;
    *Head = (*Head)->next;
    free(temp);

    printf("Removed elements is : %d\n",value);
}

int main()
{
    PNODE First = NULL;

    Enqueue(&First, 11);
    Enqueue(&First, 21);
    Enqueue(&First, 51);
    Enqueue(&First, 101);
    Enqueue(&First, 111);

    Display(First);
    printf("Number of elements in Queue is : %d\n",Count(First));

    Dequeue(&First);

    Display(First);
    printf("Number of elements in Queue is : %d\n",Count(First));

    Dequeue(&First);
    Display(First);
    printf("Number of elements in Queue is : %d\n",Count(First));

    return 0;
}