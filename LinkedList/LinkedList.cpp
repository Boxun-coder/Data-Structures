#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode,*linklist;

linklist init_linklist()
{
	linklist l=NULL;
	return l;
}

void insert_head(linklist &l)
{
	lnode *s; //New Node;
	int flag = -1;
	cout<<"Input data, read till -1\n";
	while(1)
	{
		int x;
		cin>>x;
		if(x == flag) break;
		s = (lnode*)malloc(sizeof(lnode));
		s->data=x;
		s->next=l;
		l=s;
	}
} //OK

void insert_back(linklist &l)
{
	lnode *s; //New Node
	linklist r=l; //Tail pointer
	while(r->next!=NULL)
		 r=r->next; //r = tail with data
	int flag = -1;
	cout<<"Input data, read till -1\n";
	while(1)
	{
		int x;
		cin>>x;
		if(x==flag) break;
		s = (lnode*)malloc(sizeof(lnode));
		s->data = x;
		if(l==NULL)
			l=s;
		else 
			r->next = s;
		r = s;
	}
	if(r!=NULL)
		r->next=NULL;
}

void print_list(linklist l)
{
	while(1)
	{
		cout<<l->data<<" ";
		if(l->next!=NULL)
			l = l->next;
		else break;
	}
}

int main()
{
	linklist l = init_linklist();
	insert_head(l);
	insert_back(l);
	print_list(l);
	return 0;
}
