#include <iostream>

using namespace std;


void cresc_desc(int v[50],int n)
{
    int i=0,j,m,a[50],p=0;
    while(v[i]<v[i+1])
        i++;

    m=i;
    i=0;
    j=n-1;
    while(p!=n)
    {
        if(v[i]<=v[j])
        {
            a[p]=v[i];
            i++;
            p++;
        }

        if(v[j]<v[i])
        {
            a[p]=v[j];
            j--;
            p++;
        }
    }


    for(i=0; i<p; i++)
        cout<<a[i]<<" ";

}

void desc_cresc(int v[50],int n)
{
    int i=0,j,m,a[50],p=0;
    while(v[i]>v[i+1])
        i++;
    m=i;
    i=m;
    j=m+1;
    while(p!=n)
    {
        if(v[i]<=v[j])
        {
            a[p]=v[i];
            i--;
            p++;
            if(i<0)i++;
        }

        if(v[j]<v[i])
        {
            a[p]=v[j];
            j++;
            p++;
        }

    }

    for(i=0; i<p; i++)
    {
        cout<<a[i]<<" ";
    }

}

int main()
{
    int v[50],n,i;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>v[i];

    if(v[0]<v[1])
        cresc_desc(v,n);
    else
        desc_cresc(v,n);

}
