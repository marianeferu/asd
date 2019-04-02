#include <iostream>

#include<string.h>
using namespace std;


struct nod
{
    char info[50];
    nod *st,*dr;
};

nod *radacina,*curent,*aux;

void creeare(nod* curent)
{
    if(strcmp(aux->info,curent->info)<0)
        if(curent->dr==NULL)
            curent->dr=aux;
        else
            creeare(curent->dr);

    if(strcmp(aux->info,curent->info)>0)
        if(curent->st==NULL)
            curent->st=aux;
        else
            creeare(curent->st);


}

void afisare(nod* curent)
{
    cout<<curent->info<<" ";

    if(curent->dr!=NULL)
        afisare(curent->dr);
    if(curent->st!=NULL)
        afisare(curent->st);
}

void RSD(nod* curent)
{
    cout<<curent->info<<" ";
    if(curent->st!=NULL) RSD(curent->st);
    if(curent->dr!=NULL) RSD(curent->dr);
}

void SRD(nod* curent)
{
    if(curent->st!=NULL) SRD(curent->st);
    cout<<curent->info<<" ";
    if(curent->dr!=NULL) SRD(curent->dr);
}

void SDR(nod* curent)
{
    if(curent->st!=NULL) SDR(curent->st);
    if(curent->dr!=NULL) SDR(curent->dr);
    cout<<curent->info<<" ";
}

int main()
{
    int n,i;
    char x[50];
    cout<<"Numarul de cuvinte este: ";
    cin>>n;
    radacina=new nod;

    cout<<endl<<"Cuvintele sunt:"<<endl;
    cin>>radacina->info;
    radacina->st=NULL;
    radacina->dr=NULL;



    for(i=1; i<n; i++)
    {
        aux=new nod;
        aux->st=NULL;
        aux->dr=NULL;
        cin>>aux->info;
        //cout<<aux->info<<" ";
        creeare(radacina);
    }


    cout<<"\nDupa sortarea in ord desc: ";
    SRD(radacina);
    cout<<endl;



}
