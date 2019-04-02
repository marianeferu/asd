
#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next, *prev;
};



void adauga_primul_element(node* &primul, node* &ultimul, int valoare)
{
    primul = new node;
    primul->value=valoare;
    primul->next = NULL;
    primul->prev = NULL;
    ultimul=primul;
}
void AdaugareInceput(node* &primul, int valoare)
{
    node* nou = new node;
    nou->value = valoare;
    nou->next = primul;
    nou->prev = NULL;
    primul->prev = nou;
    primul = nou;
}

void AdaugareSfarsit(node* &ultimul, int valoare)
{
    node* nou = new node;
    nou->value = valoare;
    nou->next = NULL;
    nou->prev = ultimul;
    ultimul->next = nou;
    ultimul = nou;
}
void EliminaPrimulElement(node* &primul, node* &ultimul)
{
    if(primul==ultimul)
    {
        delete primul;
        return;
    }
    node* next_element = primul->next;
    delete primul;
    primul = next_element;
}
void EliminaUltimulElement(node* &ultimul)
{
    node* anterior = ultimul->prev;
    delete ultimul;
    ultimul=anterior;
    anterior->next=NULL;
}
void Afisare(node* given_node, int type_of_navigation)
{
    node* current_node = given_node;
    cout<<'\n';
    cout<<"Afisare lista: ";
    while(current_node)
    {
        cout<<current_node->value<<" ";
        current_node = type_of_navigation == 1 ? current_node->next : current_node->prev;
    }
    cout<<'\n';
}

int main()
{
    int e,x,n;
    node* primul;
    node* ultimul;


    cout<<"\nIntroduceti elementul care urmeaza sa fie adaugat in lista: ";
    cin>>x;
    n=1;
    adauga_primul_element(primul,ultimul,x);


    cout<<"\n1) Adaugare unui element la inceputul listei";
    cout<<"\nIntroduceti elementul care urmeaza sa fie adaugat la stanga: ";
    cin>>x;
    AdaugareInceput(primul, x);
    Afisare(primul, 1);
    n++;

    cout<<"\n2) Adaugare unui element la sfarsitul listei";
    cout<<"\nIntroduceti elementul care urmeaza sa fie adaugat la dreapta: ";
    cin>>x;
    AdaugareSfarsit(ultimul, x);
    Afisare(primul, 1);
    n++;


    cout<<"\n3) Eliminarea unui element de la inceputul listei";
    if(n!=0)
    {
        cout<<"\nSe va elimina elementul din partea stanga";
        EliminaPrimulElement(primul,ultimul);
        Afisare(primul, 1);
        n--;
    }
    else
        cout<<"Lista este goala!";


    cout<<"\n4) Eliminarea unui element de la sfarsitul listei";
    if(n!=0)
    {
        cout<<"\nSe va elimina elementul din partea dreapta";
        EliminaUltimulElement(ultimul);
        Afisare(primul, 1);
        n--;
    }
    else
        cout<<"Lista este goala!";



    cout<<endl;


}
