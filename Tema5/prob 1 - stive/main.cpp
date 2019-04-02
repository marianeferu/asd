#include <iostream>

using namespace std;

struct Stack
{
    int info;
    Stack *next;
};

void Push(int x, Stack *&S)
{
    Stack *p;
    p=new Stack;
    p->info=x;
    if(S==NULL)
    {
        p->next=NULL;
        S=p;
    }
    else
    {
        p->next=S;
        S=p;
    }
}

int Pop(int x,Stack *&S)
{
    Stack *p;
    p=S;
    x=p->info;
    S=S->next;
    delete(p);
    return x;
}

int Peek(Stack *S)
{
    return S->info;
}

bool IsEmpty(Stack *S)
{
    if(S!=NULL)
        return 1;
    else
        return 0;
}

int Search(int x, Stack *S)
{
    int ok=1,i=0; // i e nivelul
    Stack *p;
    p=S;
    while(p->next!=NULL && ok==1)   //ok inca e 1 ,deci nr pozitiile
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

void Citire(Stack *&S)
{
    int x,n,i;
    cout<<"nr in stiva";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"elem adaugat in stiva";
        cin>>x;
        Push(x,S);
    }
}

void Afisare(Stack *S)
{
    Stack *p;
    p=S;
    if(p==NULL)
        cout<<"Vida";
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        cout<<endl;
        p=p->next;
    }
}

int main()
{
    Stack *S;
    S=NULL;
    Citire(S);
    cout<<"Stiva initiala este:";
    cout<<endl;
    Afisare(S);
    cout<<"\n";
    cout<<"Stiva dupa ce adaugam un element 7 in ea";
    cout<<endl;

    Push(7,S);
    Afisare(S);
    cout<<endl;

    cout<<"Stiva dupa ce scot ultimul element 7 din ea";
    cout<<endl;
    Pop(7,S);
    Afisare(S);
    cout<<endl;
    cout<<endl;


    cout<<"Elementul din varful stivei este:";
    cout<<endl;   // nivelul incepe de la 0
    cout<<Peek(S)<<"\n";

    cout<<endl;
    cout<<endl;
    IsEmpty(S);
    cout<<"Elem cautat este:";
    cout<<endl;
    cout<<endl;
    cout<<Search(8,S);
    return 0;
}
