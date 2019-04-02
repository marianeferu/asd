nclude<iostream>
#include<cmath>
using namespace std;


struct pol
{
    int grad, coef;
    pol *urm;
};
pol *p , *u;

int x,y,n,k;
pol *q, *d;

void afisare(pol *p)
{
    pol *c=p;
    while(c!=0)
    {
        cout<<c->coef<<"x^"<<c->grad<<" ";
        c=c->urm;

    }
    cout<<"\n";
}

void creare( pol *&p, pol *&u, int n, int m)
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


void creare_2( pol*&p, pol *&u, int n, int m)
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
    cout<<"Cati termeni are primul polinom ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"Coeficinetul termenului "<<i<<" este : ";
        cin>>x;
        cout<<"Gradul termenului "<<i<<" este : ";
        cin>>y;
        if(x!=0)
            creare(p,u,x,y);
    }

    cout<<"Cati termeni are al doilea polinom";
    cin>>m;

    for(int i=1; i<=m; i++)
    {
        cout<<"Coeficinetul termenului "<<i<<" este : ";
        cin>>x;
        cout<<"Gradul termenului "<<i<<" este : ";
        cin>>y;
        if(x!=0)
            creare(q,d,x,y);
    }

    afisare(p);
    cout<<"\n";
    afisare(q);
    cout<<"\n";

    pol * c, *v;
    c=p;
    v=q;

    while(c)
    {
        sum=0;
        v=q;
        while(v)
        {
            if(c->grad == v->grad)
            {
                sum=c->coef+v->coef;
                creare(l,r, sum, c->grad);
            }
            v=v->urm;
        }
        //cout<<"Suma este egala cu : "<<sum;
        if(sum==0)
            creare(l,r, c->coef, c->grad);
        c=c->urm;
        cout<<endl;
    }
    c=q;
    v=p;
    while(c)
    {
        sum=0;
        v=p;
        while(v)
        {
            if(c->grad == v->grad)
                sum=c->coef+v->coef;
            v=v->urm;
        }
        //cout<<"Suma este egala cu : "<<sum;
        if(sum==0)
            creare(l,r, c->coef, c->grad);
        c=c->urm;
        cout<<endl;
    }
    afisare(l);
    cout<<"\n";




    return 0;

}
