#include <iostream>
using namespace std;


int partition(int arr[],int start, int end)
{
    int pivot = arr[end];
    int pindex=start;
    

    for (int i = start;i<end;i++)
    {
        if (arr[i]<pivot)
        {
            int temp=arr[pindex];
            arr[pindex]=arr[i];
            arr[i]=temp;
            pindex++;
        }

    }
    arr[end]=arr[pindex];
    arr[pindex]=pivot;
    
    return pindex;
}

void quickSort(int arr[],int start, int end)
{
    if (start<end)
    {
        int p = partition(arr,start, end);
        quickSort(arr,start,(p-1));
        quickSort(arr,(p+1),end);
    }
    
}

int main()
{
    int arr[5];
    cout<<"type the elements in the list:\n";
    for (int i=0;i<5;i++)
    {
        cin >>arr[i];
    }
    cout << "Before sorting:\n";
    for (int i=0;i<5;i++)
    {
        cout<<arr[i]<< "  ";
    }

    quickSort(arr,0,4);

    cout << "\nAfter sorting:\n";
    for (int i=0;i<5;i++)
    {
        cout<<arr[i]<< "  ";
    }

    return 0;
}