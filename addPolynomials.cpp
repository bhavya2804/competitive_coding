//Add 2 polynomials using linked list
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int co;
    int po;
    node *next;
};

node* create(int co,int po,node *first)
{
    node *p= new node();
    p->co=co;
    p->po=po;
    p->next=first;
    return p;
}

node* polyAdd(node* first,node* second,node* final)
{
    while(first!=NULL && second!=NULL)
    {
        node *t=new node();
        if(first->po==second->po)
        {
            t->co=first->co+second->co;
            t->po=first->po;
            t->next=final;
            final=t;
            first=first->next;
            second=second->next;
        }
        else
        {
            if(first->po>second->po)
            {
                t->co=first->co;
                t->po=first->po;
                t->next=final;
                final=t;
                first=first->next;
            } 
            else
            {
                t->co=second->co;
                t->po=second->po;
                t->next=final;
                final=t;
                second=second->next;
            }
        }
    }    
    if(first==NULL)
    {
        while(second!=NULL)
        {
            node *t=new node();
            t->co=second->co;
            t->po=second->po;
            t->next=final;
            final=t;
            second=second->next;
        }
    }
    if(second==NULL)
    {
        while(first!=NULL)
        {
            node *t=new node();
            t->co=first->co;
            t->po=first->po;
            t->next=final;
            final=t;
            first=first->next;
        }
    }
    return final;
}

void print(node* final)
{
    while(final!=NULL)
    {
        cout<<final->co<<" "<<final->po<<endl;
        final=final->next;
    }
    return ;
}

int main()
{
    node *first=NULL;
    node *second=NULL;
    node *final=NULL;
    
    first=create(5,2,first);
    first=create(3,1,first);
    first=create(2,0,first);
    
    second=create(5,1,second);
    second=create(3,0,second);
    
    final=polyAdd(first,second,final);
    
    print(final);
    
    return 0;
}
