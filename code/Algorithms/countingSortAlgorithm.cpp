
#include <iostream>
using namespace std;

void countingSort(int inputArray[], int size,int range)
{
    int outputArray[size];
    int countArray[range];
    for (int i=0;i<range;i++)
    {
        countArray[i]=0;
    }
    for (int i=0;i<size;i++)
    {
        ++countArray[inputArray[i]];
    }
    for (int j=1;j<range;j++)
    {
        countArray[j] = countArray[j]+countArray[(j-1)];
    }
    
    for ( int i=0;i<size;i++)
    {
        outputArray[--countArray[inputArray[i]]] = inputArray[i];
    }
    for (int i =0 ; i<size;i++)
    {
        inputArray[i]=outputArray[i];
    }
}

int main ()
{
    int range = 10;
    int size;
    cout <<"type the size of list:";
    cin >> size;
    int arr[size];
    cout<<"type the elements in the list:\n";
    for (int i=0;i<size;i++)
    {
        cin >>arr[i];
    }
    cout << "Before sorting:\n";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<< "  ";
    }

    countingSort(arr,size,range);

    cout << "\nAfter sorting:\n";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<< "  ";
    }
    return 0;
}