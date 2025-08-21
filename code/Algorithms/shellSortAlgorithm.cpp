#include <iostream>
using namespace std;

void shellSort(int arr[],int size)
{
    for (int gap = size/2;gap>0;gap/=2)
    {

        
        for(int j = gap;j<size;j++)
        {
            int i=0;
            int temp = arr[j];
            for (i=j; (arr[i-gap]>temp) && (i>=gap) ;i-=gap)
            {
                arr[i]=arr[i-gap];
            }
            arr[i]=temp;
        }
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

    shellSort(arr,size);

    cout << "\nAfter sorting:\n";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<< "  ";
    }
    return 0;
}
