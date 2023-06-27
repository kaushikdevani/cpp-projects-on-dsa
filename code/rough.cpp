# include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s = "hiibro!";
    string b = "added";
    string d(1,'z');
    string c = "("+d+s+")";
    cout << c;
    return 0;
}