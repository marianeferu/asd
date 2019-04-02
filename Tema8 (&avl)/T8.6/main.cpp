#include <iostream>
#include<fstream>
using namespace std;
ifstream f("bitone.in");



int desc(int v[50],int n,int a,int b)
{
    int i=a;
    while(v[i]>=v[i+1] && i!=b)
        i++;
    if(i!=b)
        return 0;
    return 1;
}

int cresc(int v[100],int n,int a,int b)
{
    int i=a;
    while(v[i]<=v[i+1] && i!=b )
        i++;
    if(i==b)
        return 1;
    else
        return desc(v,n,i,b);

}

int main()
{
    int i,j,m,v[100],a,b,n;
    f>>n;
    for(i=0; i<n; i++)
        f>>v[i];
    f>>m;
    for(i=0; i<m; i++)
    {
        f>>a>>b;
        a--;
        b--;
        j=a;
        if(a==b)
            cout<<"1";
        else
        {
            while(v[j]==v[j+1] && j!=b)
                j++;
            if(j==b)
                cout<<"1";
            else if(v[j]>v[j+1])
                cout<<desc(v,n,j,b);
            else
                cout<<cresc(v,n,j,b);
        }
    }
}
