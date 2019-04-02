#include<iostream>
using namespace std;
int v[100], n, x;
void caut(int st, int dr)
{
int m = (st+dr)/2;
      if (x==v[m])
                   cout<<"gasit";
    else
         if (st<dr)
         if (x<v[m])
          caut(st, m-1);
         else
        caut(m+1, dr);
     else
     cout<<"nu a fost gasit.";
}
int main( )
{
 cin>>n;
for (int i=1; i<=n; i++)
cin>>v[i];

 cin>>x;
caut (1,n);
return 0;
}

