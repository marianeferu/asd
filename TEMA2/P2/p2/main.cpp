#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *next;
};

nod *p, *u;

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


void afisare()
{
    nod *aux = p;
    while (aux!= NULL)
    {
        cout<<aux->info<<" ";
        aux = aux->next;
    }
}


void MediaSauNumarare()
{
    int nrimp=0,simp=0,nrp=0,ok=0;

    nod *nou;
    nou=p;
    while (nou!=NULL)
    {
        if(nou->info%2==0)
            nrp++;
        else
        {
            simp=nou->info+simp;
            nrimp++;
            ok=1;
        }
        nou=nou->next;

    }

    if(ok==1) cout<<simp/nrimp;
    else cout<<"nu exista numere impare";
    cout<<endl;
    cout<<nrp;

}

int main()
{
    int i;

    for(i=2; i<=10; i=i+2)
        adaugare_la_final(i);
    afisare();
    cout<<endl;

    MediaSauNumarare();
}
