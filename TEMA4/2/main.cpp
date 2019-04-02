#include <iostream>

using namespace std;
/* (3 p) 2. Fie doua liste simplu inlantuite A si B, cu elementele intregi in ordine
crescatoare.
Sa se creeze o noua lista simplu inlantuita C ce contine elementele din A si
din B in ordine crescatoare. Nu se va folosi memorie suplimentara.
*/
struct Element
{
    Element *urm;
    int info;
};

struct Lista
{
    Element* primul = NULL;
    Element* ultimul = NULL;
    ~Lista()
    {
        if (!primul)
            return;
        if (primul == ultimul)
        {
            delete primul;
            primul = ultimul = NULL;
            return;
        }
        Element* precedent = primul;
        for (Element* element = primul->urm; element; element = element->urm)
        {
            delete precedent;
            precedent = element;
        }
        if (ultimul)
            delete ultimul;
        primul = ultimul = NULL;
    }

    void Adauga(int element)
    {
        Element* elementNou = new Element;
        elementNou->info = element;
        elementNou->urm = NULL;
        if (!primul && !ultimul)
        {
            primul = elementNou;
            ultimul = elementNou;
        }
        else
        {
            ultimul->urm = elementNou;
            ultimul = elementNou;
        }
    }

    void Afiseaza()
    {
        for (Element* element = primul; element; element = element->urm)
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
    cout<<"Numerele care se vor adauga in lista se dau in ordine crescatoare!!!"<<endl;
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
    Element *elementA = a.primul;
    Element *elementB = b.primul;
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
