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
    PNODE temp = Head;
    int iCnt = 0;

    do
    {
        iCnt++;
        temp = temp->next;

    }while(temp != Head);
    return iCnt;
}

void Display(PNODE Head, PPNODE Head1)
{
    PNODE temp = Head;
    int size = Count(*Head1);
    printf("%d",size);
    printf("Data from Linked List : \n");

    for(int i = 1; i < size; i++)
    {
        printf("|%d|<=>",temp->data);
        temp = temp->next;

    }
    printf("\n");
}

void InsertFirst(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

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
    (*Head)->prev = *Tail;
    (*Tail)->next = *Head;
}

void InsertLast(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

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
    (*Head)->prev = *Tail;
    (*Tail)->next = *Head;
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int iNo, int iPos)
{
    
}

void DeleteFirst(PPNODE Head, PPNODE Tail)    
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        printf("Linked List is empty \n");
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
        free((*Head)->prev);
    }
    (*Head)->prev = *Tail;
    (*Tail)->next = *Head;
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    
}

void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
{
    
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

    Display(Start, &Start);
    printf("Number of elements in Linked List are : %d\n",Count(Start));

    DeleteFirst(&Start, &End);

    Display(Start, &Start);
    printf("Number of elements in Linked List are : %d\n",Count(Start));

    return 0;
}