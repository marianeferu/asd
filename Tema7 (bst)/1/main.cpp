#include <iostream>

using namespace std;

struct Nod
{
    int info;
    Nod *lft, *rgt;
};
Nod *rad;

void Creare(Nod *&rad)
{
    int x;
    cin>>x;
    if(x!=0)
    {
        rad=new Nod;
        rad->info=x;
        cout<<"Informatia la stanga lui "<<x<<"este:";
        Creare(rad->lft);
        cout<<"Informatia la dreapta lui"<<x<<"este:";
        Creare(rad->rgt);
    }
    else
        rad=NULL;
}

void SRD(Nod *rad)
{
    if(rad!=NULL)
    {
        SRD(rad->lft);
        cout<<rad->info<<" ";
        SRD(rad->rgt);
    }
}

void RSD(Nod *rad)
{
    if(rad!=NULL)
    {
        cout<<rad->info<<" ";
        RSD(rad->lft);
        RSD(rad->rgt);
    }
}

void SDR(Nod *rad)
{
    if(rad!=NULL)
    {
        SDR(rad->lft);
        SDR(rad->rgt);
        cout<<rad->info<<" ";
    }
}

int main()
{
    Nod *rad;

    cout<<"Radacina arborelui are informatia:";
    Creare(rad);
    cout<<endl<<"Parcurgerea SRD(inordine)\n";
    SRD(rad);
    cout<<endl<<"Parcurgerea RSD(preordine)\n";
    RSD(rad);
    cout<<endl<<"Parcurgerea SDR(postordine)\n";
    SDR(rad);

    return 0;
}
