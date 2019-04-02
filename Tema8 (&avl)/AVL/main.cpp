#include <iostream>
#include<cctype>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct node
{
    int element;
    node *st;
    node *dr;
    int inaltime;
};
typedef struct node *nodeptr;

void insert(int,nodeptr &);
void del(int, nodeptr &);
int deletemin(nodeptr &);
void gaseste(int,nodeptr &);
//nodeptr gasestemin(nodeptr);
//nodeptr gasestemax(nodeptr);
void makeempty(nodeptr &);
void copy(nodeptr &,nodeptr &);
nodeptr nodecopy(nodeptr &);
//void preorder(nodeptr);
void inordine(nodeptr);
//void postordine(nodeptr);
int bsinaltime(nodeptr);
nodeptr srl(nodeptr &);
nodeptr drl(nodeptr &);
nodeptr srr(nodeptr &);
nodeptr drr(nodeptr &);
int max(int,int);
int faranoduri(nodeptr);



void   insert(int x,nodeptr &p)
{
    if (p == NULL)
    {
        p = new node;
        p->element = x;
        p->st=NULL;
        p->dr = NULL;
        p->inaltime=0;
        if (p==NULL)
        {
            cout<<"Out of Space\n"<<endl;
        }
    }
    else
    {
        if (x<p->element)
        {
            insert(x,p->st);
            if ((bsinaltime(p->st) - bsinaltime(p->dr))==2)
            {
                if (x < p->st->element)
                {
                    p=srl(p);
                }
                else
                {
                    p = drl(p);
                }
            }
        }
        else if (x>p->element)
        {
            insert(x,p->dr);
            if ((bsinaltime(p->dr) - bsinaltime(p->st))==2)
            {
                if (x > p->dr->element)
                {
                    p=srr(p);
                }
                else
                {
                    p = drr(p);
                }
            }
        }
        else
        {
            cout<<"Elementul exista deja\n"<<endl;
        }
    }
    int m,n,d;
    m=bsinaltime(p->st);
    n=bsinaltime(p->dr);
    d=max(m,n);
    p->inaltime = d + 1;
}
nodeptr gasestemin(nodeptr p)
{
    if (p==NULL)
    {
        cout<<"Arborele este gol\n"<<endl;
        return p;
    }
    else
    {
        while(p->st !=NULL)
        {
            p=p->st;
            //return p;
        }
        return p;
    }
}

nodeptr  gasestemax(nodeptr p)
{
    if (p==NULL)
    {
        cout<<"Arborele este gol\n"<<endl;
        return p;
    }
    else
    {
        while(p->dr !=NULL)
        {
            p=p->dr;
            //return p;
        }
        return p;
    }
}
// gasire element

void  gaseste(int x,nodeptr &p)
{
    if (p==NULL)
    {
        cout<<"Elementul nu a fost gasit\n"<<endl;
    }
    else
    {
        if (x < p->element)
        {
            gaseste(x,p->st);
        }
        else
        {
            if (x>p->element)
            {
                gaseste(x,p->dr);
            }
            else
            {
                cout<<"Elementul a fost gasit!\n"<<endl;
            }
        }
    }
}


void  copy(nodeptr &p,nodeptr &p1)
{
    makeempty(p1);
    p1 = nodecopy(p);
}

void makeempty(nodeptr &p)
{
    nodeptr d;
    if (p != NULL)
    {
        makeempty(p->st);
        makeempty(p->dr);
        d=p;
        free(d);
        p=NULL;
    }
}
// Copiaza nodurile
nodeptr nodecopy(nodeptr &p)
{
    nodeptr temp;
    if (p==NULL)
    {
        return p;
    }
    else
    {
        temp = new node;
        temp->element = p->element;
        temp->st = nodecopy(p->st);
        temp->dr = nodecopy(p->dr);
        return temp;
    }
}



void  del(int x,nodeptr &p)
{
    nodeptr d;
    if (p==NULL)
    {
        cout<<"Elementul nu a fost gasit\n"<<endl;
    }
    else if ( x < p->element)
    {
        del(x,p->st);
    }
    else if (x > p->element)
    {
        del(x,p->dr);
    }
    else if ((p->st== NULL) && (p->dr == NULL))
    {
        d=p;
        free(d);
        p=NULL;
        cout<<"Elementul a fost sters\n"<<endl;
    }
    else if (p->st == NULL)
    {
        d=p;
        free(d);
        p=p->dr;
        cout<<"Elementul a fost sters\n"<<endl;
    }
    else if (p->dr == NULL)
    {
        d=p;
        p=p->st;
        free(d);
        cout<<"Elementul a fost sters\n"<<endl;
    }
    else
    {
        p->element = deletemin(p->dr);
    }
}


int   deletemin(nodeptr &p)
{
    int c;
    cout<<"in deltemin\n"<<endl;
    if (p->st == NULL)
    {
        c=p->element;
        p=p->dr;
        return c;
    }
    else
    {
        c=deletemin(p->st);
        return c;
    }
}

void preordine(nodeptr p)
{
    if (p!=NULL)
    {
        cout<<p->element<<"\t";
        preordine(p->st);
        preordine(p->dr);
    }
}


void  inordine(nodeptr p)
{
    if (p!=NULL)
    {
        inordine(p->st);
        cout<<p->element<<"\t";
        inordine(p->dr);
    }
}


void postordine(nodeptr p)
{
    if (p!=NULL)
    {
        postordine(p->st);
        postordine(p->dr);
        cout<<p->element<<"\t";
    }
}

int max(int val1, int val2)
{
    return ((val1 > val2) ? val1 : val2);
}
int bsinaltime(nodeptr p)
{
    int t;
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        t = p->inaltime;
        return t;
    }
}

nodeptr  srl(nodeptr &p1)
{
    nodeptr p2;
    p2 = p1->st;
    p1->st = p2->dr;
    p2->dr = p1;
    p1->inaltime = max(bsinaltime(p1->st),bsinaltime(p1->dr)) + 1;
    p2->inaltime = max(bsinaltime(p2->st),p1->inaltime) + 1;
    return p2;
}
nodeptr srr(nodeptr &p1)
{
    nodeptr p2;
    p2 = p1->dr;
    p1->dr = p2->st;
    p2->st = p1;
    p1->inaltime = max(bsinaltime(p1->st),bsinaltime(p1->dr)) + 1;
    p2->inaltime= max(p1->inaltime,bsinaltime(p2->dr)) + 1;
    return p2;
}
nodeptr  drl(nodeptr &p1)
{
    p1->st=srr(p1->st);
    return srl(p1);
}
nodeptr drr(nodeptr &p1)
{
    p1->dr = srl(p1->dr);
    return srr(p1);
}

int faranoduri(nodeptr p)
{
    int numara=0;
    if (p!=NULL)
    {
        faranoduri(p->st);
        faranoduri(p->dr);
        numara++;
    }
    return numara;
}

int main()
{

    nodeptr root,max;
    int a,gasesteele,stergeele;



    root = NULL;



    cout<<"Pune o valoare: ";
    cin>>a;
    insert(a,root);


    cout<<"Pune o valoare: ";
    cin>>a;
    insert(a,root);
    cout<<"Pune o valoare: ";
    cin>>a;
    insert(a,root);
    cout<<"Pune o valoare: ";
    cin>>a;
    insert(a,root);
    cout<<"Pune o valoare: ";
    cin>>a;
    insert(a,root);
    cout<<"Pune o valoare: ";
    cin>>a;
    insert(a,root);
    cout<<"Pune o valoare: ";
    cin>>a;
    insert(a,root);
    cout<<"Pune o valoare: ";
    cin>>a;
    insert(a,root);


    if (root !=NULL)
    {
        max=gasestemax(root);
        cout<<"\nElementul maxim din arbore este: "<<max->element<<endl;
    }

    cout<<"\n\t\tPREORDINE"<<endl;
    preordine(root);
    cout<<endl;

    cout<<"\nNodul cautat: ";
    cin>>gasesteele;
    if (root != NULL)
    {
        gaseste(gasesteele,root);
    }

    cout<<"\nNodul pe care il sterg este: ";
    cin>>stergeele;
    del(stergeele,root);
    inordine(root);
    cout<<endl;

    cout<<"\n\t\tPREORDINE"<<endl;
    preordine(root);
    cout<<endl;

    cout<<"\n\t\tINORDINE"<<endl;
    inordine(root);
    cout<<endl;

    cout<<"\n\t\tPOSTORDINE "<<endl;
    postordine(root);
    cout<<endl;





    return 0;
}
