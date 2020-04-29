#include "iostream"
using namespace std;

typedef struct StackNode
{
    int data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

bool Push(LinkStack &S, int data)
{
    StackNode *s=(StackNode*)malloc(sizeof(StackNode));
    s->data=data;
    s->next=S.top;
    S.top=s;
    S.count++;
    return true;
}

bool StackEmpty(LinkStack *p)
{
    if(p->top == NULL) return true;
    else return false;
}

bool Pop(LinkStack *S)
{
    LinkStackPtr p;
    if(StackEmpty(S))
        return false;//Stack Empty
    p = S->top;
    free(p);
    return true;
}
