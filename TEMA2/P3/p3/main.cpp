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

void adaugare_la_mijloc(int inf,int k)
{
    nod *nou;
    nou=new nod;
    nou -> info = inf;


    if(p == NULL)
    {
        p = u = nou;
        nou->next = NULL;
        return;
    }

    if(k == 1)
    {
        nou ->next = p;
        p = nou;
        return;
    }

    nod *aux = p;
    ///cautam pozitia k(numaratoarea incepe de la 1), deci trebuie sa avansam cu k-1 pozitii
    for(int i=2; i<k; i++)
    {
        ///nu avem k elemente
        aux = aux->next;
        if(aux == NULL)
        {
            cout<<"Nu exista k elemente in lista, inserarea nu a fost efectuata!\n";
            return;
        }
    }
    ///poz k e u nod
    if(aux == u)
    {
        u->next = nou;
        nou->next = NULL;
        u = nou;
    }
    else
    {
        nou->next = aux->next;
        aux->next = nou;
    }
}


void Media ()
{
    float med;
    nod *nou;
    nou=p;
    while(nou!=NULL&& nou->next!=NULL)
    {
        med= ((nou->info + nou->next->info)/2);

        nod *aux = new nod;
        aux->info = med;
        aux->next = nou->next;
        nou->next = aux;
        nou=aux->next;
    }
}

int main()
{
    int i,n;
    cin>>n;
    for(i=1; i<=n; i++)

        adaugare_la_final(i);
    afisare();
    cout<<endl;

    Media();
    afisare();
}
