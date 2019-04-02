#include <iostream>
using namespace std;

void heapmax(int v[], int n, int i)
{
    int maxim = i;  // cel mai mare nod devine radacina
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // Daca st e mai mare decat radacina
    if (l < n && v[l] > v[maxim])
        maxim = l;

    // Daca st e mai mare decat radacina
    if (r < n && v[r] > v[maxim])
        maxim = r;

    // Daca maxim nu e radacina
    if (maxim != i)
    {
        swap(v[i], v[maxim]);

        // Recursiv, facem heap max
        heapmax(v, n, maxim);
    }
}


void heapSort(int v[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapmax(v, n, i);


    for (int i=n-1; i>=0; i--)
    {
        // Muta radacina pe ultimul fiu adaugat
        swap(v[0], v[i]);


        heapmax(v, i, 0);
    }
}


void Afiseaza(int v[], int n)
{
    for (int i=0; i<n; ++i)
        cout << v[i] << " ";
    cout << "\n";
}


int main()
{
    int n, v[200];

    cout<<"Numarul de elem din vector:";
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>v[i];
    heapSort(v, n);

    cout << "Vectorul sortat este: \n";
    Afiseaza(v, n);
}
