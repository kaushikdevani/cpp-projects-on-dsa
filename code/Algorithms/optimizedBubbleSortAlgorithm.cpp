#include <iostream>
using namespace std;

void optimizedBubbleSort(int arr[])
{
    for (int i=0;i<5;i++)
    {
        bool changed = false;
        for(int j=0;j<5-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                changed = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
        }
        if (!changed)
            break;
    }
}

int main()
{
  int myarray[5];
  int size;
  cout << "Enter 5 integers in any order: " << endl;
  for (int i = 0; i < 5; i++) {
    cin >> myarray[i];
  }
  cout << "Before Sorting" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  optimizedBubbleSort(myarray); // sorting happens here

  cout << endl << "After Sorting" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}