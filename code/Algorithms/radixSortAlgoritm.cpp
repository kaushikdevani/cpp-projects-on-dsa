#include <iostream>
using namespace std;

int getMax(int arr[], int size)
{
    int m = arr[0];
    for (int i =0;i<size;i++)
    {
        if (arr[i]>m)
            m = arr[i];
    }
    return m;

}

void countingSort(int arr[],int size, int div)
{
    int outputArray[size];
    int countArray[10]={0};
    for (int i =0;i<size;i++)
    {
        ++countArray[((arr[i]/div)%10)];
    }
    for (int i =1;i<11;i++)
    {
        countArray[i] = countArray[i] + countArray[(i-1)];
    }
    for (int i =(size-1);i>=0;i--)
    {
        outputArray[--countArray[((arr[i]/div)%10)]]=arr[i];
    }
    for (int i =0;i<size;i++)
    {
        arr[i]=outputArray[i];
    }
}
void radixSort(int arr[],int size)
{
    int m = getMax(arr,size);
    for ( int div =1;(m/div)>0;div*=10)
    {
        countingSort(arr,size,div);
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

    radixSort(arr,size);

    cout << "\nAfter sorting:\n";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<< "  ";
    }
    return 0;
}