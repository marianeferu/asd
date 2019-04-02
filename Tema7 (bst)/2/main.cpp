#include <iostream>

using namespace std;

struct Nod
{
    int info;
    Nod *lft, *rgt;
};
Nod *rad;

void Inserare(int x)
{
    Nod *p,*q;
    p=rad;
    if(rad==NULL)
    {
        p=new Nod;
        p->info=x;
        p->lft=p->rgt=NULL;
        rad=p;
    }
    else
    {
        while(p!=NULL)
        {
            q=p;
            if(x<=p->info)
                p=p->lft;
            else
                p=p->rgt;
        }
        p=new Nod;
        p->info=x;
        p->lft=p->rgt=NULL;
        if(x>q->info)
            q->rgt=p;
        else
            q->lft=p;
    }
}

int Search(Nod *rad, int x)
{
    if(rad!=NULL)
    {
        if(rad->info==x)
            return 1;
        return Search(rad->lft,x);
        return Search(rad->rgt,x);
    }
}

int maxim;
void FindMax(Nod *rad)
{
    if(rad!=NULL)
    {
        FindMax(rad->lft);
        if(rad->info>maxim)
            maxim=rad->info;
        FindMax(rad->rgt);
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

void functie_supl(Nod *&c, Nod *&f)
{
    Nod *aux;
    if(f->rgt)
        functie_supl(c, f->rgt);
    else
    {
        c->info=f->info;
        aux=f;
        f=f->lft;
        delete aux;
    }
}

void sterg(Nod *&c, int n)
{
    Nod *f,*aux;
    if(c)
        if(c->info==n)
            if(c->rgt==0 && c->lft==0) //daca e nod terminal
            {
                delete c;
                c=0;
            }
            else if(c->lft==0)
            {
                aux=c->rgt;
                delete c;
                c=aux;
            }
            else if(c->rgt==0)
            {
                aux=c->lft;
                delete c;
                c=aux;
            }

            else        functie_supl(c, c->lft);  //are ambii suborordonati
        else if(c->info<n)
            sterg(c->rgt, n);
        else
            sterg(c->lft, n);
    else
        cout<<"Valoarea de sters nu se gaseste in arbore";
}

int main()
{
    rad=NULL;
    int i,n,x;

    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>x;
        Inserare(x);
    }

    RSD(rad);

    ///b
    cout<<"\n";
    if(Search(rad,45)==1)
        cout<<"1 ->DA\n";
    else
        cout<<"0 ->NU\n";

    ///c
    FindMax(rad);
    cout<<maxim<<"\n";

    ///d
    sterg(rad,60);
    cout<<"dupa stergerea nodului 2, arborele contine:"<<endl;
    RSD(rad);
    return 0;
}
