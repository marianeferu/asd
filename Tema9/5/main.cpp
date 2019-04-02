#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");


void insertion(int v[50],int org,int n)
{
    int i,val,poz;
    for(poz=org; poz<=n; poz++)
    {
        val=v[poz];
        i=poz-1;
        while(v[i]>val && i>0)
        {
            v[i+1]=v[i];
            i--;
        }
        v[i+1]=val;
    }
}



void quickSort(int v[50],int st,int dr)
{
    int i=st,j=dr,tmp;
    int pivot=v[(st+dr)/2];
    if(j-i<=11)
        insertion(v,i,j-i);
    else
    {
        while (i<=j)
        {
            while (v[i]<pivot)
                i++;
            while (v[j]>pivot)
                j--;
            if (i<=j)
            {
                swap(v[i],v[j]);
                i++;
                j--;
            }
        }

        if (st<j)
            quickSort(v,st,j);
        if (i<dr)
            quickSort(v,i,dr);
    }

}

int main()
{
    int v[50],n,i;
    f>>n;
    for(i=0; i<n; i++)
        f>>v[i];
    quickSort(v,0,n-1);

    for(i=0; i<n; i++)
        cout<<v[i]<<" ";


}
