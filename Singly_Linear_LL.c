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
    while (Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

void Display(PNODE Head)
{   
    printf("Elements from Linked List are : \n");
    while(Head != NULL)
    {
        printf("|%d|->",Head->data);
        Head = Head->next;
    }
    printf("|NULL|-+\n");
}

void InsertFirst(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
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

void InsertAtPos(PPNODE Head, int iNo, int iPos)
{ 
    int size = Count(*Head);

    if((iPos < 1) || (iPos > size+1))
    {
        printf("Invalid Position\n");
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
        PNODE temp = NULL;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;

        temp = *Head;

        for(int i = 1; i < iPos -1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)    
{
    if(*Head == NULL)        
    {
        return;
    }

    PNODE temp = *Head;

    temp = *Head;
    *Head = (*Head)->next;
    free(temp);
}

void DeleteLast(PPNODE Head)
{
    if(*Head == NULL) 
    {
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
        printf("Invalid Position\n");
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
        PNODE temp = NULL;
        PNODE tempdelete = NULL;

        temp = *Head;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        tempdelete = temp->next;
        temp->next = temp->next->next;
        free(tempdelete);
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
    InsertAtPos(&First, 1, 1);
    InsertAtPos(&First, 75, 5);
    InsertAtPos(&First, 151, 8);

    Display(First);
    printf("Number of elements in Linked List are : %d\n",Count(First));

    DeleteFirst(&First);

    Display(First);
    printf("Number of elements in Linked List are : %d\n",Count(First));


    Display(First);
    printf("Number of elements in Linked List are : %d\n",Count(First));

    return 0;
}