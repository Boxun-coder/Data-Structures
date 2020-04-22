## Linked list summary 
> Linked list is a pointer that points to the head of the link list.
#### Structure

The struct is shown below. `Datatype` is what will be stored in data block.
```c
typedef struct linklist
{
	Datatype Data;
	struct linklist *next; 
}*linklist,lnode;
```

#### Initialize

```cpp
linklist CreateLinkedlist()
{
    linklist l;
    l -> next = NULL;
    return l;
}
```

#### Insert

First apply for memory for the new node:

`lnode *p = new lnode;`
or in C,

```c
lnode *p =(lnode*)malloc(sizeof(lnode));
```

Insert a new node between `p` and `p->next`:

```cpp
s->next = p->next;
p->next = s; 
```

If the order is reversed, `p` will point to s while s will point to itself, i.e., `s = s->next=p->next`  .

#### Delete
Delete a node with index `i`:
If `i==0`, let the second element to be the head of the linked list.
If `i!=0`, let `j=1` and `p`  points to head. Iterate `p` until `i=j`. 

```cpp
q = p->next;
p->next=q->next;
delete q; //free(q);
```

 