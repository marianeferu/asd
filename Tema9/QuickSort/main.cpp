#include<iostream>
#include<cstdlib>

using namespace std;


void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int Partition(int a[], int low, int high)
{
    int pivot, index, i;
    index = low;
    pivot = high;

    //gasesc indexul pivotului
    for(i=low; i < high; i++)
    {
        if(a[i] < a[pivot])
        {
            swap(&a[i], &a[index]);
            index++;
        }
    }

    swap(&a[pivot], &a[index]);

    return index;
}


int RandomPivotPartition(int a[], int low, int high)
{
    int pivot, n, temp;


    n = rand();



    pivot = low + n%(high-low+1);


    swap(&a[high], &a[pivot]);

    return Partition(a, low, high);
}


int QuickSort(int a[], int low, int high)
{
    int pindex;
    if(low < high)
    {

        pindex = RandomPivotPartition(a, low, high);

        QuickSort(a, low, pindex-1);
        QuickSort(a, pindex+1, high);
    }
    return 0;
}

int main()
{
    int n, i;
    cout<<"Numarul elementelor care trebuiesc sortate: ";
    cin>>n;

    int v[n];
    for(i = 0; i < n; i++)
    {
        cout<<"Elementul "<<i+1<<" este : ";
        cin>>v[i];
    }

    QuickSort(v, 0, n-1);


    cout<<"\nDupa sortare: ";
    for (i = 0; i < n; i++)
        cout<<" "<<v[i];

    return 0;
}
