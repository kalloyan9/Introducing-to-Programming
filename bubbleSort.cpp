#include<iostream>
#include<cstdlib>
using namespace std;

void readArray(int *array, unsigned size)
{
    for(int i = 0 ; i < size ; ++i )
        cin >> array[i];
}
void printArray(int *array, unsigned size)
{
    for(int i = 0 ; i < size ; ++i )
        cout << array[i] << " ";

    cout<<endl;
}
void generateArray(int *array, unsigned size)
{
    for (unsigned i = 0; i < size; ++i) {
        array[i] = rand() % 1000;
    }
}
const int *minElement(const int *A, unsigned size)
{
    const int *min = A;
    for(int i = 1 ; i < size ; ++i)
    {
        if(A[i] < *min)
            min = A + i;
    }
    return min;
}

void swap(int *a , int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void bubbleSort(int *array, int size)
{
    int i, j;
    for (i = 0; i < size-1; i++)
    {
        for (j = 0; j < size-1-i; j++)
        {
            if (array[j+1] < array[j])
                swap(array+j+1, array+j);
        }
    }
}

int main (){
    unsigned n;
    cin >> n;
    int *A = new int [n];
    generateArray(A,n);
    printArray(A,n);
    bubbleSort(A,n);
    printArray(A,n);

    delete[] A;
    cout << endl;
    return 0;
}
