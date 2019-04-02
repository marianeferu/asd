#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *next;

};

nod *p, *u;

void afisare()
{
    nod *aux = p;
    while (aux!= NULL)
    {
        cout<<aux->info<<" ";
        aux = aux->next;
    }
}

void adaugare_la_final (int inf)
{
    nod *nou;
    if(p==0)
    {
        p= new nod;
        p->next=NULL;
        p->info=inf;
        u=p;
    }
    else
    {
        nou= new nod;
        nou->info=inf;
        nou->next=NULL;
        u->next=nou;
        u=nou;
    }
}

void Add(Nod *&nou, int x)
{
    p=nou;
    u=new nod;
    u->info=x;
    while(p->next!=NULL)
        p=p->next;
    p->next=u;
    u->next=NULL;
}

void suma()
{
    int x,y,z,ok1,ok2;
    p=H->leg;
    q=G->leg;
    ok1=ok2=1;
    while(ok1==1 && ok2==1)
    {
        if(p!=NULL) ok1=1;
        else ok1=0;
        if(q!=NULL) ok2=1;
        else ok2=0;
        if(ok1==1 && ok2==1)
        {
            x=p->info + q->info;
            y=x%10;
            Add(K,y);
            z=x/10;
            p->leg->info+=z;
            p=p->leg;
            q=q->leg;
        }
    }

    while(p!=NULL)
    {
        x=p->info;
        Add(K,x);
        p=p->leg;
    }

    while(q!=NULL)
    {
        x=q->info;
        Add(K,x);
        q=q->leg;
    }
}
