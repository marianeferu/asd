#include <iostream>

using namespace std;



   int CautSecv(int a[],int n, int x)
  { for(int i=1;i<=n;i++)
      {if(a[i]==x) return 1;}

        return 0;


  }

int main()
{ int a[200],x,n;

cin>>x;
cin>>n;
 for(int i=1;i<=n;i++)
    cin>>a[i];

   cout<<CautSecv(a,n,x);
}
