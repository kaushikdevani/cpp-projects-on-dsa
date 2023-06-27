//linked with github


#include <iostream>
using namespace std;

int binarySearch(int arr[],int left, int right, int num)
{
    while(left<=right)
    {
        int middle = left+(right-left)/2;
        if (arr[middle]==num)
            return middle;
        else if (arr[middle]<num)
            left=middle+1;
        else if (arr[middle]>num)
            right = middle-1;
    }
    return -1;
}

int main() 
{
  int arr[10];
  cout << "Please enter 10 elements of the Array in ASSENDING order" << endl;
  for (int i = 0; i < 10; i++) {
    cin >> arr[i];
  }
  cout << "Please enter an element to search" << endl;
  int num;
  cin >> num;

  int index = binarySearch(arr,0,9,num);
  if (index==-1)
    cout<< "No Match Found";
  else 
    cout<<"Match found at position: " << index+1 << endl;

  return 0;
}