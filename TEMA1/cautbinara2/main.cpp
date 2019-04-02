#include<iostream>
using namespace std;
int n,x,v[100],m;

int caut (int st, int dr)
{
    if(st>dr)
        return -1;
    else
        {
            m =(st+dr)/2;
            if (x==v[m])
                return m;
            if (x<v[m])
                return caut(st,m-1);
            else
                return caut(m+1,dr);
        }
}
int main()
{ int ok=0;
    cin>>n;

    for (int i=1;i<=n;i++)
        cin>>v[i];
        cin>>x;
  ok= caut(1,n);
     if(ok=!-1) cout<<"gasit";
         else cout<<"nu exista";          //doar caut(1,n) afiseaza pozitia
    return 0;
}
