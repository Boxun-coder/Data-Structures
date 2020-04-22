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

void print_list(linklist l)
{
	if(l==NULL)
	{
		cout<<"Void\n";
		return;
	}
	while(1)
	{
		cout<<l->data<<" ";
		if(l->next!=NULL)
			l = l->next;
		else break;
	}
	cout<<endl;
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

bool insert_position(linklist &l,int position, int value)
{
	cout<<"Before insertion: "<<endl;
	print_list(l);
	lnode *s;
	linklist t = l;
	while(position!=0)
	{
		if(t->next!=NULL)
		{
			t=t->next;
			position--;
		}
		else return false;
	}
	s = (lnode*)malloc(sizeof(lnode));
	s->data = value;
	s->next = t->next;
	t->next = s;
	cout<<"After Insertion: "<<endl;
	print_list(l);
	return true;
}

void delete_position(linklist &l, int position)
{
	lnode *p=l;
	lnode *q;
	if(position==0)
	{
		q = p->next;
		delete p;
		l = q;
		cout<<"After deletion:\n";
		print_list(l);
		return;
	}
	int j = 1;
	while(p->next!=NULL && j<position)
	{
		p=p->next;
		++j;
	}
	if(!(p->next) || j>position)
	{
		cout<<"element does not exist";
		return;
	}
	q = p->next;
	p->next=q->next;
	delete q;
	cout<<"After deletion:\n";
	print_list(l);
	return;
}

void delete_list(linklist &l)
{
	lnode* p=l;
	lnode* q;
	while(p!=NULL)
	{
		q = p->next;
		delete p;
		p=q;
	}
	l = NULL;
	return;
}

int main() //Test functions
{
	linklist l = init_linklist();
	insert_head(l);
	insert_back(l);
	insert_position(l,0,100); //Test
	print_list(l);
	delete_position(l,0);  //Test
	delete_list(l);
	print_list(l);
	return 0;
}
