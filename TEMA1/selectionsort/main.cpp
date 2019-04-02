#include <iostream>

using namespace std;

   void SelectionSort( int a[],int n)
{
    for(int i=1;i<=n-1;i++)
    {
        int k=i;
        int minim=a[i];
        for(int j=i+1;j<=n;j++)
            if(a[j]<minim)
              {k=j;
               minim=a[j];
               }
              a[k]=a[i];
              a[i]=minim;

        }

    }





 int main()
    { int i, n,a[100];

        cin>>n;
        for(i=1;i<=n;i++)
         cin>>a[i];
        SelectionSort(a,n);
          for(i=1;i<=n;i++)
          cout<<a[i]<<" ";


    }
