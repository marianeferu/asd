#include<iostream>
#include<fstream>
using namespace std;
int a[20][20],c[20],v[20],ns,n,comp;
int prim;
int ultim;


int nod_nevizitat(int v[20], int n)
{
    for(int i=1; i<=n; i++)
        if(v[i]==0)
            return i; // primul nod nevizitat
    return 0;   // nu mai exista noduri nevizitate
}
void parcurgere_latime(int a[20][20], int n,int ns)
{
    comp++;
    v[ns]=1;
    cout<<"Componenta conexa "<<comp<<" :  ";
    cout<<ns<<" ";
    prim=ultim=1;
    c[ultim]=ns;
    while(prim<=ultim)
    {
        for(int i=1; i<=n; i++)
            if(a[c[prim]][i]==1)
                if(v[i]==0)
                {
                    ultim++;
                    c[ultim]=i;
                    cout<<i<<" ";
                    v[i]=1;
                }
        prim++;
    }
    cout<<endl;
}
int main()
{
    ifstream f("graf.in");
    int x,y;
    f>>n;
    while(f>>x>>y)
        a[x][y]=a[y][x]=1;
    f.close();

    cout<<"Matricea de adiacenta este : "<<endl;
    for( int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;

    parcurgere_latime(a,n,1); //cin>>ns;


    while(nod_nevizitat(v,n)!=0)
    {
        ns=nod_nevizitat(v,n);
        parcurgere_latime(a,n,ns);
    }
    cout<<endl;
    cout<<endl;

    cout<<"Graful are "<<comp <<" componente conexe ";
    cout<<endl;
    cout<<endl;

    return 0;
}
