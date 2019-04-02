
/* 1 2 2 1 3 3 4 4 caz corect

 se pun in stiva 1 2 2
  2 si 2 pereche, le scot pe ambele, ramane 1

  adaug 1, aveam 1 si le scot pe ambele

  3 3 pereche
  4 4 pereche



  1 2 2 3 1 4 3 4 caz incorect

  se pun in stiva 1 2 2
   2 si 2 pereche, le scot pe ambele, ramane 1

   adaug 3 si 1
   nu sunt pereche, deci nu pot anula
*/
#include <iostream>

using namespace std;

struct Stack
{
    int info;
    Stack *next;
};

void Push(Stack *S)
{
    int x;
    cin>>x;
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

int Pop(int x)
{
    Stack *S;
    Stack *p;
    p=S;
    x=p->info;
    S=S->next;
    delete(p);
    return x;
}

int Peek(Stack *S)
{
    if(x==p->info);
    return 1;
    else return 0;
}

bool IsEmpty(Stack *S)
{
    if(S!=NULL)
        return 1;
    else
        return 0;
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

    while(S)
    {
        if(Peek(S)==Push(S))
            Pop(S);
        Pop(S);
    }

    Afisare(S);


}
