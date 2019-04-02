#include <iostream>
#include<fstream>
using namespace std;

int a[20][20];

int grad( int i, int n)
{
    int s, j;
    s=0;
    for(j=1; j<=n; j++)
        s=s+a[i][j];
    return s;
}

int numar_muchii(int n)
{
    int nr=0, muchii;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(a[i][j]==1) nr++;
    muchii=nr/2;
    return muchii;
}

void gradMax(int n)
{
    int i,gr, maxx = 0;
    for(i = 1; i <= n; i++)
    {
        int gr = grad(i,n);
        if(gr > maxx)
            maxx = gr;
    }

    cout<<"Noduri care au gradul maxim sunt/este= ";
    for(i = 1; i <= n; i++)
    {
        int gr = grad(i,n);
        if(gr == maxx)
            cout<<i;
    }
}

int main()
{
    int i,j,n,m,x,y;
    ifstream f("graf.txt");
    f>>n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            f>>a[i][j];
        }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;

    for(i=1; i<=n; i++)
        cout<<"varful "<<i<<" are gradul; "<< grad(i,n)<<endl;

    cout<<endl;
    cout<<endl;
    cout<<"Numarul de muchii din graful neorientat este: "<< numar_muchii(n);
    cout<<endl;

    gradMax(n);


    cout<<endl;
    cout<<endl;
}
