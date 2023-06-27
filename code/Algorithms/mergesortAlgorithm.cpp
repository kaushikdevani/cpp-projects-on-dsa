#include <iostream>
using namespace std;

void merge(int arr[],int left,int middle,int right)
{
    int temp[5];
    int i = left;
    int j=middle+1;
    int z=left;
    while(i<=middle && j<=right)
    {
        if (arr[i]<arr[j])
        {
            temp[z]=arr[i];
            z++;
            i++;
        }
        else 
        {
            temp[z]=arr[j];
            j++;
            z++;
        }        
    }

    while(i<=middle)
    {
        temp[z]=arr[i];
        i++;
        z++;
    }
    while(j<=right)
    {
        temp[z]=arr[j];
        j++;
        z++;
    }

    for (int s =left;s<=right;s++)
    {
        arr[s]=temp[s];
    }
}

void mergeSort(int arr[],int left,int right)
{
    
    if(left<right)
    {
        int middle= left + (right - left) / 2;
        mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);
        merge(arr,left,middle,right);
    }
}

int main()
{
    int arr[5];
    cout<<"type the elements in the lsit:\n";
    for (int i=0;i<5;i++)
    {
        cin >>arr[i];
    }
    cout << "Before sorting:\n";
    for (int i=0;i<5;i++)
    {
        cout<<arr[i]<< "  ";
    }

    mergeSort(arr,0,4);

    cout << "\nAfter sorting:\n";
    for (int i=0;i<5;i++)
    {
        cout<<arr[i]<< "  ";
    }

    return 0;
}