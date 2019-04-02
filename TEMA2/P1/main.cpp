#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *next;
};

nod *p, *u;

void adaugare_la_inceput(int inf)
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


void afisare()
{
    nod *aux = p;
    while (aux!= NULL)
    {
        cout<<aux->info<<" ";
        aux = aux->next;
    }
    cout<<"\n\n";
}


void cautare_dupa_valoare(int x)
{
    int  ok=0;

    nod *nou;

    nou=p;
    while(nou!=NULL && ok==0)
    {
        if(nou->info==x)
        {
            ok=1;
            u=nou;
        }
        nou=nou->next;
    }
    if(ok==1)
        cout<<"exista";
    else
        cout<<"nu exista";
}

void cautare_dupa_pozitie(int pozitia)
{
    int i=1;

    u=p;
    while (u != NULL && i < pozitia)
    {
        u = u->next;
        i++;
    }
    cout<< u->info;
}

void stergere_valoare (int x)
{
    nod *aux;

    u=p;
    if(p->info==x)
    {
        aux=p;
        p=p->next;
        delete aux;
    }
    else
    {
        u=p;
        while(u->next->info!=x && u!=NULL)
            u=u->next;
        aux=u->next;
        u->next=aux->next;
        delete aux;
    }
}

void stergere_pozitie(int pozitia)
{
    int i;

    nod *aux;

    if(pozitia==1)
    {
        aux=p;
        p=p->next;
        delete aux;
    }
    else
    {
        u=p;
        for(i=2; i<pozitia; i++)
            u=u->next;
        aux=u->next;
        u->next=aux->next;
        delete aux;
    }
}

void stergere_lista()
{
    nod *aux = p;

    while (p!=NULL)
    {
        aux = p;
        p=p->next;
        delete aux;
    }

}

int main()
{
    int i,n,k,inf,x;

    cout<<"adaugat elem de la 1 la 10 la final\n";
    for(i=1; i<=10; i++)
        adaugare_la_final(i);
    afisare();

    cout<<"adaugat elem de la 90 la 100 la inceput\n";
    for(i=90; i<=100; i++)
        adaugare_la_inceput(i);
    afisare();

    cout<<"adaug pe pozitia 300 elem 50\n";
    adaugare_la_mijloc(50,300);
    afisare();

    cout<<"caut valoarea 50: ";
    cautare_dupa_valoare(50);
    cout<<"\n";

    cout<<"pe pozitia 2 este elementul ";
    cautare_dupa_pozitie(2);
    cout<<"\n\n";

    cout<<"sterg valoarea 90\n";
    stergere_valoare(90);
    afisare();

    cout<<"sterg pozitia 5\n";
    stergere_pozitie(5);
    afisare();

    cout<<"sterg toata lista\n";
    stergere_lista();
    afisare();

    return 0;
}
