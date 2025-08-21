#include <iostream>
#include <stack>
using namespace std;

bool operand(char c)
{
    if ((c>='a')&&(c<='z')||(c>='A')&&(c<='Z'))
        return true;
    else
        return false;
}

string PostfixToInfix(string prefix)
{
    stack <string> stack;
    string infix;

    for ( int i=(prefix.length()-1);i>=0;i--)
    {
        string op(1,prefix[i]);
        if (operand(prefix[i])) 
            stack.push(op);

        else
        {
            string a = stack.top();
            stack.pop();
            string b = stack.top();
            stack.pop();
            string n = "("+a+op+b+")";
            stack.push(n);
        }
    }
    return  stack.top();
}

int main()
{
    string infix,prefix;
    cout << "Enter the postfix expression: \n";
    cin>>prefix;
    cout << "postfix expression: \n"<<prefix<<endl;

    infix = PostfixToInfix(prefix);

    cout << "Infix expression: \n"<<infix<<endl;
    return 0;
}