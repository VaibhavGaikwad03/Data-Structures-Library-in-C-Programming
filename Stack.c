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
    printf("Data from the stack is : \n");

    while(Head != NULL)
    {
        printf("|%d|->",Head->data);
        Head = Head->next;
    }
    printf("\n");
}

void Push(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    newn->next = *Head;
    *Head = newn;
}

void Pop(PPNODE Head)
{
    PNODE temp = *Head;
    int value = 0;

    if(*Head == NULL)
    {
        printf("Stack is empty \n");
        return;
    }

    *Head = (*Head)->next;
    value = temp->data;
    free(temp);
    printf("Removed element is : %d\n",value);

}

int main()
{
    PNODE First = NULL;

    Push(&First, 111);
    Push(&First, 101);
    Push(&First, 51);
    Push(&First, 21);
    Push(&First, 11);

    Display(First);
    printf("Number of elements in Queue is : %d\n",Count(First));

    Pop(&First);
    Pop(&First);

    Display(First);
    printf("Number of elements in Queue is : %d\n",Count(First));

    return 0;
}