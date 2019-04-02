#include <iostream>

using namespace std;

struct Element
{
    Element *urm;
    int info;
};

struct Lista
{
    Element* p = NULL;
    Element* u = NULL;

    Lista()
    {
        if (!p)
            return;
        if (p == u)
        {
            delete p;
            p = u = NULL;
            return;
        }
        Element* precedent = p;
        for (Element* element = p->urm; element; element = element->urm)
        {
            delete precedent;
            precedent = element;
        }
        if (u)
            delete u;
        p = u = NULL;
    }

    void Adauga(int element)
    {
        Element* elementNou = new Element;
        elementNou->info = element;
        elementNou->urm = NULL;
        if (!p && !u)
        {
            p = elementNou;
            u = elementNou;
        }
        else
        {
            u->urm = elementNou;
            u = elementNou;
        }
    }

    void Afiseaza()
    {
        for (Element* element = p; element; element = element->urm)
            cout<<element->info<<" ";
        cout<<endl;
    }
};

int main()
{
    Lista a, b, c;
    int n,m,k;
    cout<<"Cate elemente va avea lista A?\n";
    cin>>n;
    cout<<"Cate elemente va avea lista B?\n";
    cin>>m;
    cout<<"Numerele adaugate in lista sunt in ordine crescatoare!"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Element ce urmeaza sa fie adaugat in lista A: ";
        cin>>k;
        a.Adauga(k);
    }
    for(int i=0; i<m; i++)
    {
        cout<<"Element ce urmeaza sa fie adaugat in lista B: ";
        cin>>k;
        b.Adauga(k);
    }
    cout<<"Lista A arata astfel: ";
    a.Afiseaza();
    cout<<"Lista B arata astfel: ";
    b.Afiseaza();
    Element *elementA = a.p;
    Element *elementB = b.p;
    while (elementA && elementB)
    {
        if (elementA->info < elementB->info)
        {
            c.Adauga(elementA->info);
            elementA = elementA->urm;
        }
        else
        {
            c.Adauga(elementB->info);
            elementB = elementB->urm;
        }
    }
    while (elementA)
    {
        c.Adauga(elementA->info);
        elementA = elementA->urm;
    }


    while (elementB)
    {
        c.Adauga(elementB->info);
        elementB = elementB->urm;
    }
    cout<<"Lista C arata astfel: ";
    c.Afiseaza();
    return 0;
}

