#include <iostream>
#include <fstream>
using namespace std;
ifstream f("roata.in");
ofstream g("roata.out");

struct cabina
{
    int rotiri,client;
    cabina *next;

};

cabina *curent,*prim,*ajutor;

int main()
{
    int n,p,coada[100],coborari[100],i,suma=0,m=0,m1=0,a=0;
    f>>n>>p;
    for(i=0; i<p; i++)
    {
        f>>coada[i];
        suma+=coada[i];
    }
    g<<suma<<endl;

    prim=new cabina;
    curent=prim;
    for(i=0; i<n-1; i++)
    {
        curent->rotiri=-1;
        ajutor=new cabina;
        curent->next=ajutor;
        curent=ajutor;
    }
    curent->rotiri=-1;
    curent->next=prim;

    curent=prim;
    for(i=0; i<n; i++)
    {
        if(curent->rotiri==-1)
        {
            curent->rotiri=coada[m];
            curent->client=m+1;
            m++;
        }
        curent=curent->next;
    }
    while(m1!=p)
    {

        if(curent->rotiri>0)
        {
            curent->rotiri--;
            if(curent->rotiri==0)
            {
                coborari[m1]=curent->client;
                m1++;
                curent->rotiri=coada[m];
                curent->client=m+1;
                m++;
            }
        }
        curent=curent->next;

    }
    for(i=0; i<m1; i++)
        g<<coborari[i]<<" ";
    while(curent!=prim)
    {
        a++;
        curent=curent->next;
    }
    g<<endl<<n-a;


}
