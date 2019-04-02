#include<iostream>
using namespace std;

struct node
{
    int value;
    node *next, *prev;
};
void read_n(int &n)
{
    cout<<"Introduceti numarul elementelor din lista: ";
    cin>>n;
}
void CerinteProblema()
{
    cout<<"\n0) Se opreste executarea problemei";
    cout<<"\n1) Adaugarea unui element la inceputul listei";
    cout<<"\n2) Adaugarea unui element la sfarsitul listei";
    cout<<"\n3) Adaugarea unui element in interiorul listei";
    cout<<"\n4) Afisareaa elementelor in ordine";
    cout<<"\n5) Afisarea elementelor in ordine inversa";
    cout<<"\n6) Stergerea unui element din lista stiind numarul lui de ordine";
    cout<<"\n7) Stergerea unui element din lista stiind valoarea numarului";
}


void CreareLista(node* &first_node, node* &last_node, int n)
{
    first_node = new node;
    cout<<"\nElementul ce urmeaza sa fie adaugat in lista este: ";
    cin>>first_node->value;
    first_node->next = NULL;
    first_node->prev = NULL;
    node* aux_first_node = first_node;
    for (int i = 1; i < n; i++)
    {
        node* new_node = new node;
        cout<<"Elementul ce urmeaza sa fie adaugat in lista este: ";
        cin>>new_node->value;
        first_node->next = new_node;
        new_node->next = NULL;
        new_node->prev = first_node;
        first_node = new_node;
    }
    last_node = first_node;
    first_node = aux_first_node;
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

void AdaugareInceput(node* &first_node, int node_info)
{
    node* new_node = new node;
    new_node->value = node_info;
    new_node->next = first_node;
    new_node->prev = NULL;
    first_node->prev = new_node;
    first_node = new_node;
}

void AdaugareSfarsit(node* &last_node, int node_info)
{
    node* new_node = new node;
    new_node->value = node_info;
    new_node->next = NULL;
    new_node->prev = last_node;
    last_node->next = new_node;
    last_node = new_node;
}

void AdaugareMijloc(node* &first_node, int node_info, int position)
{
    int i = 1;
    node* new_node = new node;
    new_node->value = node_info;
    node* current_left_node;
    node* current_right_node = first_node;
    while (current_right_node && i != position)
    {
        i++;
        current_right_node = current_right_node->next;
    }
    if (current_right_node)
    {
        current_left_node = current_right_node->prev;
        current_left_node->next = new_node;
        new_node->prev = current_left_node;
        current_right_node->prev = new_node;
        new_node->next = current_right_node;
        return;
    }
    cout<<"\nPozitia introdusa nu este una valida";
}

void StergePozitie(node* &first_node, int position)
{
    int i = 1;
    node* current_element = first_node;
    while (current_element && i != position)
    {
        i++;
        current_element = current_element->next;
    }
    if (current_element)
    {
        node* left_element = current_element->prev;
        node* right_element = current_element->next;
        delete current_element;
        left_element->next = right_element;
        right_element->prev = left_element;
        return;
    }
    cout<<"\nPozitia introdusa nu este valida";
}

void StergeValoare(node* &first_node, int node_info)
{
    node* current_element = first_node;
    while(current_element && current_element->value != node_info)
    {
        current_element = current_element->next;
    }
    if (current_element)
    {
        node* left_element = current_element->prev;
        node* right_element = current_element->next;
        delete current_element;
        left_element->next = right_element;
        right_element->prev = left_element;
        return;
    }
    cout<<"\nValoarea introdusa nu se afla in lista";
}

int main()
{
    int n;
    int type;
    int x, position;
    node* first_node;
    node* last_node;
    cout<<"Problema 1";
    CerinteProblema();
    cout<<"\nIntroduceti numarul problemei alese: ";
    cin>>type;
    if(type==0)
    {
        return 0;
    }
    read_n(n);
    CreareLista(first_node, last_node, n);
    while (type)
    {
        switch (type)
        {
        case 1:

            cout<<"\nIntroduceti elementul care urmeaza sa fie adaugat in lista: ";
            cin>>x;
            AdaugareInceput(first_node, x);
            Afisare(first_node, 1);
            break;

        case 2:

            cout<<"\nIntroduceti elementul care urmeaza sa fie adaugat in lista: ";
            cin>>x;
            AdaugareSfarsit(last_node, x);
            Afisare(first_node, 1);
            break;

        case 3:

            cout<<"\nIntroduceti elementul care urmeaza sa fie adaugat in lista: ";
            cin>>x;
            cout<<"Introduceti pozitia pe care urmeaza sa fie inserat elementul: ";
            cin>>position;
            AdaugareMijloc(first_node, x, position);
            Afisare(first_node, 1);
            break;

        case 4:

            Afisare(first_node, 1);
            break;

        case 5:

            Afisare(last_node, 0);
            break;

        case 6:

            cout<<"Introduceti pozitia de pe care urmeaza sa fie sters elementul: ";
            cin>>position;
            StergePozitie(first_node, position);
            Afisare(first_node, 1);
            break;

        case 7:

            cout<<"\nIntroduceti elementul care urmeaza sa fie sters din lista: ";
            cin>>x;
            StergeValoare(first_node, x);
            Afisare(first_node, 1);
            break;
        }
        CerinteProblema();
        cout<<"\nIntroduceti numarul problemei alese: ";
        cin>>type;
    }
    return 0;
}
