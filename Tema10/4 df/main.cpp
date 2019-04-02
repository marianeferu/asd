#include<iostream>
#include<fstream>
using namespace std;
int a[20][20],c[20],v[20],n;


void parcurgere_adancime(int k) //DF stiva
{
    v[k]=1;
    cout<<k<<" ";
    for(int x=1; x<=n; x++)
        if(a[k][x]==1) // adiacent cu varful stivei
            if(v[x]==0)  //nevizitat
                parcurgere_adancime(x);
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

    int k;
    cout<<"Nodul start; ";
    cin>>k;
    parcurgere_adancime(k);
    return 0;
}
