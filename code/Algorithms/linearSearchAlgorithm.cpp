#include <iostream>
using namespace std;

void linearSearch(int arr[], int num)
{
    bool found = false;
    for (int i =0;i<5;i++)
    {
        if (num==arr[i])
        {
            found = true;
            cout<<"Element:"<< num << ", found at position:"<<i+1<<endl;
        }
    }
    if (!found)
    {
        cout << "Element:"<<num<<", does not Exist in the given list."<<endl;
    }
}

int main() {
  int arr[5];
  cout << "Please enter 5 elements of the Array" << endl;
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }
  cout << "Please enter an element to search" << endl;
  int num;
  cin >> num;

  linearSearch(arr, num);

  return 0;
}