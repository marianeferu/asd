#include <iostream>
#include <conio.h>
using namespace std;


struct nod
{
    int info;
    nod *next;

};

nod *p, *u;

int afiseaza( )
{
    nod *i;

    i=p;

    while(i!=NULL)
    {
        cout<<i->info<<' ';
        i=i->next;
    }



}

void adaugfinal (int inf)
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

void adauginceput(int inf)
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
        nou->next=p;
        p=nou;


    }



}

int main()
{
    int n, inf;
    cin>>n;


    while(n--)
    {
        cin>>inf;
        adauginceput(inf);
    }
    afiseaza();
}
