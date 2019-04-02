#include <iostream>

using namespace std;
int n,m,a,b;

struct pol
{
    int grad,coef;
    pol *next;

};


pol *p, *u;

void afisare(pol *p)
{
    pol *aux = p;
    while (aux!= NULL)
    {
        cout<<aux->coef<<"x^ "<<aux->grad<<" ";

    }
}

void creare (pol *&p, pol *&u,int n,int m)
{

    pol *aux;
    if(p==0)
    {
        p=new pol;
        p->coef=n;
        p->grad=m;
        p->next=0;
        u=p;

    }
    else
    {
        pol *nou;
        nou=new pol;
        nou->coef=n;
        nou->grad=m;
        nou->next=p;
        p=nou;
    }

}

int main()
{
    int x,y,n,k;
    cout<<"Cati termeni are polinomul?";
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cout<<"Coef termenului"<<i<<"este=";
        cin>>x;
        cout<<"Gradul termenului"<<i<<"este=";
        cin>>y;
        if(x!=0) creare(p,u,x,y);
    }

    cout<<"Inmultesc coef pol cu ";
    cin>>k;


    afisare(p);
    cout<<endl;
    pol *aux=p;
    while(aux)
    {
        aux->coef=aux->coef*k;
        aux=aux->next;
    }

    afisare(p);

}
