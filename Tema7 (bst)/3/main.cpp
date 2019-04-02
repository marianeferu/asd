#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *st;
    nod *dr;
};
nod *r;
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
    else if(x>r->info)
        Adauga(r->dr,x);
    else cout<<"Valoarea se repeta si nu va mai fi adaugata in sir";
}
void SRD(nod *&r)   ///inordine
{
    if(r)
    {
        SRD(r->st);
        cout<<r->info<<" ";
        SRD(r->dr);
    }
}
int n,i,x;
int main()
{
    cout<<"Cate numere contine sirul";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        Adauga(r,x);
    }
    cout<<"Lista de numere ordonate:";
    SRD(r);
    return 0;
}
