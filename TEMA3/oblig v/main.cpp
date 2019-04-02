#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *next;
};

nod *p;

void adaugaSortat(int info)
{
    if(p == NULL)
    {
        p = new nod;
        p -> info = info;
        p -> next = NULL;
        return;
    }

    nod *aux = new nod;
    aux->info = info;

    if(p -> next==NULL)
    {
        if(p->info<=info) // adaug dupa p
        {
            p->next=aux;
            aux->next=NULL;
        }

        else
        {
            aux->next=p;        // adaug inainte de p
            p=aux;
        }

        return;
    }

    nod *nou =p;
    while(nou->next!=NULL && nou->next->info <info)
        nou=nou->next;

    aux->next=nou->next;
    nou->next=aux;
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
int main()
{
    adaugaSortat(2);
    adaugaSortat(1);
    adaugaSortat(5);
    adaugaSortat(3);

    afisare();
}
