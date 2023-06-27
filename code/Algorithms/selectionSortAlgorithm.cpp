#include <iostream>
using namespace std;

void selectionSort(int arr[])
{
    for(int i =0 ; i<4;i++)
    {
        int min = i;
        for (int j=(i+1);j<5;j++)
        {
            if (arr[min]>arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        } 
    }
}

int main()
{
    int myarr[5];
    cout << "Enter 5 integers in random order: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> myarr[i];
    }

    cout << "UNSORTED ARRAY: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << myarr[i] << "  ";
    }
    cout << endl;

    selectionSort(myarr); // sorting is happening here

    cout << "SORTED ARRAY: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << myarr[i] << "  ";
    }
    return 0;
}