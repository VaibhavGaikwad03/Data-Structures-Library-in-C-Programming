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
    PNODE temp = Head;
    int iCnt = 0;

    do
    {
        iCnt++;
        temp = temp->next;

    }while(temp != Head);
    return iCnt;
}

void Display(PNODE Head)
{
    PNODE temp = Head;

    printf("Data from Linked List : \n");
    do
    {
        printf("|%d|->",temp->data);
        temp = temp->next;

    }while(temp != Head);
    printf("NULL\n");
}

void InsertFirst(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
    (*Tail)->next = *Head;
}

void InsertLast(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        *Tail = newn;
    }
    (*Tail)->next = *Head;
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int iNo, int iPos)
{
    int size = Count(*Head);

    if((iPos < 1) || (iPos > size+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head, Tail, iNo);
    }
    else if(iPos == size+1)
    {
        InsertLast(Head, Tail, iNo);
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = *Head;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;

        for(int i = 1; i < iPos -1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head, PPNODE Tail)    
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        printf("Linked list is empty\n");
        return;
    }

    if((*Head)->next == *Head)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Tail)->next);
        (*Tail)->next = *Head;
    }
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        printf("Linked list is empty\n");
        return;
    }

    if((*Head)->next == *Head)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        PNODE temp = *Head;

        while(temp->next != *Tail)
        {
            temp = temp->next;
        }
        free(*Tail);
        *Tail = temp;
        (*Tail)->next = *Head;
    }
}

void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
{
    int size = Count(*Head);

    if((iPos < 1) || (iPos > size))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head, Tail);
    }
    else if(iPos == size)
    {
        DeleteLast(Head, Tail);
    }
    else
    {
        PNODE temp = *Head;
        PNODE tempdelete = NULL;

        for(int i = 1; i < iPos -1; i++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = tempdelete->next;
        free(tempdelete);
    }
}

int main()
{
    PNODE Start = NULL;
    PNODE End = NULL;

    InsertFirst(&Start, &End, 51);
    InsertFirst(&Start, &End, 21);
    InsertFirst(&Start, &End, 11);
    InsertLast(&Start, &End, 101);
    InsertLast(&Start, &End, 111);
    InsertAtPos(&Start, &End, 1, 1);
    InsertAtPos(&Start, &End, 75, 5);
    InsertAtPos(&Start, &End, 151, 8);

    Display(Start);
    printf("Number of elements in Linked List are : %d\n",Count(Start));

    DeleteFirst(&Start, &End);
    DeleteLast(&Start, &End);

    Display(Start);
    printf("Number of elements in Linked List are : %d\n",Count(Start));

    DeleteAtPos(&Start, &End, 5);

    Display(Start);
    printf("Number of elements in Linked List are : %d\n",Count(Start));

    return 0;
}