#include<iostream>
#include<cmath>
#include<string>
using namespace std;


struct pol
{
    int  coef;
    char grad;
    pol *urm;
};
pol *p , *u;

int x,n,k;
pol *q, *d;
char y;

void afisare(pol *p)
{
    pol *c=p;
    while(c!=0)
    {
        cout<<c->coef<<c->grad<<" ";
        c=c->urm;

    }
    cout<<"\n";
}

void creare( pol *&p, pol *&u, int n, char m)
{
    pol *c;
    if(p==0)
    {
        p=new pol;
        p->coef=n;
        p->grad=m;
        p->urm=0;
        u=p;
    }
    else
    {
        pol *nou;
        nou= new pol;
        nou->coef=n;
        nou->grad=m;
        nou->urm=p;
        p=nou;
    }
}


void creare_2( pol*&p, pol *&u, int n, char m)
{
    pol *c;
    if(p==0)
    {
        p=new pol;
        p->coef=n;
        p->grad=m;
        p->urm=0;
        u=p;
    }
    else
    {
        c=new pol;
        c->coef=n;
        c->grad=m;
        c->urm=0;
        u->urm=c;
        u=c;
    }


}



int main()
{
    int m, sum=0;
    pol *l=0, *r=0;
    cout<<"Cati termeni are primul vector";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"Valoarea termenului "<<i<<" este : ";
        cin>>x;
        cout<<"Indicele termenului "<<i<<" este : ";
        cin>>y;
        creare(p,u,x,y);
    }

    cout<<"Cati termeni are al doilea vector";
    cin>>m;

    for(int i=1; i<=m; i++)
    {
        cout<<"Valoarea termenului "<<i<<" este : ";
        cin>>x;
        cout<<"Indicele termenului "<<i<<" este : ";
        cin>>y;
        creare(q,d,x,y);
    }

    afisare(p);
    cout<<"\n";
    afisare(q);
    cout<<"\n";

    pol * c, *v;
    c=p;
    v=q;
    sum=0;
    int sum2;
    int prod;
    while(c)
    {
        sum2=0;
        prod=0;
        v=q;
        while(v)
        {
            if(c->grad == v->grad)
            {
                prod=c->coef*v->coef;
                sum=sum+prod;
                cout<<c->coef+v->coef<<" ";
            }

            v=v->urm;
        }



        c=c->urm;
        cout<<endl;
    }
    cout<<"Produsul scalar este : "<<sum;
    cout<<"\n";




    return 0;

}
