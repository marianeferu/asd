#include <iostream>

using namespace std;

   void BubbleSort(int a[],int n)
    {for(int j=2;j<=n;j++)
       { for(int i=n;i>=j;i--)
          if(a[i-1]>a[i])
          {int aux=a[i-1];
          a[i-1]=a[i];
          a[i]=aux;

          }

        }
    }

 int main()
    { int i, n,a[100];

        cin>>n;
        for(i=1;i<=n;i++)
         cin>>a[i];
        BubbleSort(a,n);
          for(i=1;i<=n;i++)
          cout<<a[i]<<" ";


    }
