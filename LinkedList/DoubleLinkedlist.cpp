#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct dlinklist
{
    int data;
    struct dlinklist *prior;
    struct dlinklist *next;
} dnode,*dlist;


