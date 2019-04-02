#include <iostream>

using namespace std;

struct Queue
{
    int info;
    Queue *next;
};

int n;

void Push(Queue *&Q, int x)
{
    Queue *p,*q;
    p=new Queue;
    p->info=x;
    if(Q==NULL)
    {
        p->next=NULL;
        Q=p;

    }
    else
    {
        p=Q;
        while(p->next!=NULL)
            p=p->next;
        q=new Queue;
        q->info=x;
        q->next=p->next;
        p->next=q;

    }
}

int Pop(int x,Queue *&Q)
{
    Queue *p;
    p=Q;
    x=p->info;
    Q=Q->next;
    delete p;
    return x;
}

int Peek(Queue *Q)
{
    return Q->info;
}

void Citire(Queue *&Q)
{
    int i,x;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        Push(Q,x);
    }
}

bool Empty(Queue *Q)
{
    if(Q==NULL)
        return 1;
    else
        return 0;
}

int Search(Queue *Q, int x)
{
    int i=0,ok=1; //ok=1 inca nu l-am gasit,deci nr pozitiile
    Queue *p;
    p=Q;
    while(p->next!=NULL && ok==1)
    {
        if(x==p->info)
            ok=0;
        p=p->next;
        i++;
    }
    i--;
    if(ok==1)
        return -1;
    else
        return i;


}

void Afisare(Queue *Q)
{
    Queue *p;
    p=Q;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int main()
{
    Queue *Q;
    Q=NULL;
    cout<<"Coada initiala are un nr de elemente:";
    Citire(Q);
    Afisare(Q);

    cout<<endl;
    cout<<endl;
    cout<<"Coada dupa ce adaugam un element 10 in ea";
    cout<<endl;
    Push(Q,10);
    Afisare(Q);

    cout<<endl;
    cout<<endl;
    cout<<"Afisez elem 10 scos din coada si coada finala";
    cout<<endl;
    cout<<Pop(10,Q)<<"\n";
    Afisare(Q);

    cout<<endl;
    cout<<"Elementul care este primul in coada";
    cout<<endl;
    cout<<Peek(Q)<<"\n";

    Empty(Q);

    cout<<endl;
    cout<<"Distanta la care se gaseste elem 5 este (incepe de la 0)";
    cout<<endl;
    cout<<Search(Q,5);

    return 0;
}
