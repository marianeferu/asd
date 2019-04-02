#include <iostream>
#include <stack>
#include<cstring>
using namespace std;

struct Stack
{
    int info;
    Stack *leg;
};

void Push(int x, Stack *&S)
{
    Stack *p;
    p=new Stack;
    p->info=x;
    if(S==NULL)
    {
        p->leg=NULL;
        S=p;
    }
    else
    {
        p->leg=S;
        S=p;
    }
}

void Pop(Stack *&S)
{
    Stack *p;
    p=S;
    S=S->leg;
    delete(p);
}

int Peek(Stack *S)
{
    return S->info;
}

bool IsEmpty(Stack *S)
{
    if(S==NULL)
        return 1;
    else
        return 0;
}

void Citire(Stack *&S)
{
    int n,i,poz=0;
    char x[]="()()(";
    n= strlen(x);
    for(i=0; i<n; i++)
    {
        if(IsEmpty(S) && x[i]=='(')
        {
            poz++;
            Push((int)x,S);
            continue;

        }
        if(IsEmpty(S) && x[i]==')')
        {
            poz++;
            Push((int)x,S);
            break;

        }
        if(Peek(S)==x[i])
        {
            Push((int)x,S);
            poz++;
            //ok1=1;
        }
        else
        {
            Pop(S);
            poz++;

        }

    }
    if(IsEmpty(S))
        cout<<"este parantezat corect";
    else
        cout<<"nu este parantezat corect"<<endl<<"Pe pozitia"<<" "<<poz<<" este prima paranteza fara corespondent";
}



int main()
{
    Stack *S;
    S=NULL;
    Citire(S);
    return 0;
}

