#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *st;
    nod *dr;
};
nod *q,*prim;
void Adauga(nod* &r,int x)
{
    if(!r)
    {
        r=new nod;
        r->info=x;
        r->st=r->dr=NULL;
    }
    else if(x<r->info)
        Adauga(r->st,x);
    else if(x>=r->info)
        Adauga(r->dr,x);
    else
        cout<<"Valoarea deja exista";
}

void SRD(nod *&r)
{
    if(r)
    {
        SRD(r->st);
        cout<<r->info<<" ";
        SRD(r->dr);
    }
}
void cautare(nod *p,int x)
{
    if(!p)
        cout<<p->info;
    else if(x<p->info)
        cautare(p->st,x);
    else if(x>p->info)
        cautare(p->dr,x);
    else cout<<"Nu exista astfel de valori in sir!";
}
void afisare(nod *r,int k1,int k2)
{
    if(r)
        if(r->info>=k1&&r->info<=k2)
        {
            afisare(r->st,k1,k2);
            cout<<r->info<<" ";
            afisare(r->dr,k1,k2);
        }
        else
        {
            afisare(r->st,k1,k2);
            afisare(r->dr,k1,k2);
        }
}

int main()
{
    nod *aux;
    int n,i,x,k1,k2;
    cout<<"Nr de elemente ale arborelui:";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        Adauga(prim,x);
    }
    cout<<"Arborele:";
    SRD(prim);
    cout<<endl<<"k1=";
    cin>>k1;
    cout<<"k2=";
    cin>>k2;
    if(k1==k2)
        cautare(prim,k1);
    else
        afisare(prim,k1,k2);
    return 0;
}

