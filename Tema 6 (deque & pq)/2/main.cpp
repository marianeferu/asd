#include <iostream>

using namespace std;

struct coada_cu_prioritati
{
    int priority;
    int value;
    coada_cu_prioritati* next;
};

void CreareCoada(coada_cu_prioritati* &primul_element, int nb_of_elem)
{
    primul_element = new coada_cu_prioritati;
    cout<<"\nIntroduceti prioritatea primului element: ";
    cin>>primul_element->priority;
    cout<<"Introduceti valoarea primului element: ";
    cin>>primul_element->value;
    primul_element->next = NULL;
    coada_cu_prioritati* aux_primul_element = primul_element;
    for (int i = 1; i < nb_of_elem; i++)
    {
        coada_cu_prioritati* new_element = new coada_cu_prioritati;
        cout<<"\nIntroduceti prioritatea urmatorului element: ";
        cin>>new_element->priority;
        cout<<"Introduceti valoarea urmatorului element: ";
        cin>>new_element->value;
        coada_cu_prioritati* current_element = aux_primul_element;
        coada_cu_prioritati* left_element = NULL;
        while (current_element && current_element->priority <= new_element->priority)
        {

            if (current_element->next)
                if (current_element->next->priority > new_element->priority)
                    left_element = current_element;
            current_element = current_element->next;
        }
        if (current_element)
        {
            if (left_element)
            {
                left_element->next = new_element;
                new_element->next = current_element;
            }

            else
            {
                new_element->next = current_element;
                aux_primul_element = new_element;
            }

            continue;
        }
        primul_element->next = new_element;
        new_element->next = NULL;
        primul_element = new_element;
    }
    primul_element = aux_primul_element;
}

void AfisareCoada(coada_cu_prioritati* primul_element)
{
    if (!primul_element)
    {
        cout<<"\nCoada este goala!";
        return;
    }
    coada_cu_prioritati* current_element = primul_element;
    cout<<'\n';

    while (current_element)
    {
        cout<<"Elementul "<<current_element->value<<" ( cu prioritatea "<<current_element->priority<<" );"<<endl;
        current_element = current_element->next;
    }
}

void AdaugareElement(coada_cu_prioritati* &primul_element, int priority, int element_value)
{
    coada_cu_prioritati* current_element = primul_element;
    coada_cu_prioritati* left_element = NULL;
    coada_cu_prioritati* aux_primul_element = primul_element;
    coada_cu_prioritati* new_element = new coada_cu_prioritati;
    new_element->priority = priority;
    new_element->value = element_value;
    while (current_element && current_element->priority <= priority)
    {

        if (current_element->next)
            if (current_element->next->priority > priority)
                left_element = current_element;
        current_element = current_element->next;
    }

    if (current_element)
    {
        if (left_element)
        {
            left_element->next = new_element;
            new_element->next = current_element;
        }

        else
        {

            new_element->next = current_element;
            aux_primul_element = new_element;
        }

        primul_element = aux_primul_element;
        return;
    }
    coada_cu_prioritati* ultimul_element = primul_element;
    while (ultimul_element->next)
        ultimul_element = ultimul_element->next;
    ultimul_element->next = new_element;
    new_element->next = NULL;
    primul_element = aux_primul_element;
}

void EliminaPrimulElement(coada_cu_prioritati* &primul_element)
{
    coada_cu_prioritati* next_element = primul_element->next;
    delete primul_element;
    primul_element = next_element;
}

int main()
{
    int n,x,y;
    coada_cu_prioritati* first_node;
    coada_cu_prioritati* last_node;
    cout<<"Cate elemente va contine coada?"<<endl;
    cin>>n;
    if(n==0)
    {
        cout<<"Coada este goala!";
        return 0;
    }
    CreareCoada(first_node,n);
    AfisareCoada(first_node);
    cout<<endl<<"Se va adauga elementul: ";
    cin>>x;
    cout<<"Cu prioritatea: ";
    cin>>y;
    AdaugareElement(first_node, y, x);
    AfisareCoada(first_node);
    cout<<endl<<"Se va elimina primul element: ";
    EliminaPrimulElement(first_node);
    AfisareCoada(first_node);
    return 0;
}
