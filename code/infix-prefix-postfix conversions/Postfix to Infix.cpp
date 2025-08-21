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

string PostfixToInfix(string postfix)
{
    stack <string> stack;
    string infix;

    for ( int i=0 ; i< postfix.length();i++)
    {
        string op(1,postfix[i]);
        if (operand(postfix[i])) 
            stack.push(op);

        else
        {
            string a = stack.top();
            stack.pop();
            string b = stack.top();
            stack.pop();
            string n = "("+b+op+a+")";
            stack.push(n);
        }
    }
    return  stack.top();
}

int main()
{
    string infix,postfix;
    cout << "Enter the postfix expression: \n";
    cin>>postfix;
    cout << "postfix expression: \n"<<postfix<<endl;

    infix = PostfixToInfix(postfix);

    cout << "Infix expression: \n"<<infix<<endl;
    return 0;
}