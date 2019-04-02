#include <iostream>
using namespace std;

struct Element
{
    Element *urm;
    int info;
};

struct Lista
{
    Element* p= NULL;
    Element* u= NULL;

    Lista()
    {
        if (!p)
            return;
        if (p == u)
        {
            delete p;
            p= u= NULL;
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
        p= u= NULL;
    }

    void Adauga(int element)
    {
        Element* elementNou = new Element;
        elementNou->info = element;
        elementNou->urm = NULL;
        if (!p&& !u)
        {
            p= elementNou;
            u= elementNou;
        }
        else
        {
            u->urm = elementNou;
            u= elementNou;
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
    Lista a, b;
    int n,k;
    int v[100];
    cout<<"Cate elemente va avea lista A?\n";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Elementul ce urmeaza sa fie adaugat in lista A: ";
        cin>>k;
        a.Adauga(k);
        v[i]=k;
    }
    cout<<"Lista A arata astfel: ";
    a.Afiseaza();
    n--;
    for(int i=n; i>=0; i--)
    {
        k=v[i];
        b.Adauga(k);
    }
    cout<<"Lista B arata astfel: ";
    b.Afiseaza();
    return 0;
}
