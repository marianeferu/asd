#include<iostream>
using namespace std;

//COMBINAREA A CELOR DOUA JUMATATI V[L..M] SI V[M+1...R]

void merge(int v[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    // copiaza informatiile in L SI R
    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1+ j];

    // Combina v [l...r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

// Copiaza ce a ramas in l, daca a mai ramas ceva

    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    // Copiaza ce a ramas in r, daca a mai ramas ceva
    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int v[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; // contra overflow
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main()
{
    int n;
    cout<<"nr de elem="<<" ";
    cin>>n;
    int v[n];
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        cout<<endl;
    }

    mergeSort(v,0,n-1);

    cout<<"Sortat este"<<endl;
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";

}
