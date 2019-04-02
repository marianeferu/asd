#include <iostream>

using namespace std;




     void InsertionSort(int a[], int n)
   {

         for( int i=2;i<=n;i++)
         {
             int x=a[i];
             int j=i-1;
             while(j>0 && a[j]>x)
             { a[j+1]=a[j];
             j--;

             }
             a[j+1]=x;
         }

   }


int main()
    { int i, n,a[100];


        cin>>n;
        for(i=1;i<=n;i++)
         cin>>a[i];
        InsertionSort(a,n);
          for(i=1;i<=n;i++)
          cout<<a[i]<<" ";
return 0;

    }
