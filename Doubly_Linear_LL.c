#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int Count(PNODE Head)
{
    int iCnt = 0;

    while (Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

void Display(PNODE Head)
{
    printf("Elements from the Linked List are : \n");
    printf("NULL<=>");

    while (Head != NULL)
    {   
        printf("|%d|<=>",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
    
}

void InsertFirst(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        (*Head)->prev = newn;
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

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
        newn->prev = temp;
    }
}

void InsertAtPos(PPNODE Head, int iNo, int iPos)
{
    int size = Count(*Head);

    if((iPos < 1) || (iPos > size+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head, iNo);
    }
    else if(iPos == size+1)
    {
        InsertLast(Head, iNo);
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = *Head;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Head)->prev);
        (*Head)->prev = NULL;
    }
}

void DeleteLast(PPNODE Head)
{
    if(*Head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        PNODE temp = *Head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int size = Count(*Head);

    if((iPos < 1) || (iPos > size))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        PNODE temp = *Head;


        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);
    InsertLast(&First, 101);
    InsertLast(&First, 111);

    Display(First);
    printf("Number of elements in Linked List are : %d\n",Count(First));

    DeleteFirst(&First);
    DeleteLast(&First);

    Display(First);
    printf("Number of elements in Linked List are : %d\n",Count(First));

    InsertAtPos(&First, 75, 3);

    Display(First);
    printf("Number of elements in Linked List are : %d\n",Count(First));

    DeleteAtPos(&First, 3);

    Display(First);
    printf("Number of elements in Linked List are : %d\n",Count(First));

    return 0;
}