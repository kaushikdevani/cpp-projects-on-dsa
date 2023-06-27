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

string PostfixToPrefix(string postfix)
{
    stack <string> stack;
    for (int i=0;i<postfix.length();i++)
    {
        string op(1,postfix[i]);
        if (operand(postfix[i]))
            stack.push(op);
        else
        {
            string op1 = stack.top();
            stack.pop();
            string op2 = stack.top();
            stack.pop();
            string exp = op+op2+op1;
            stack.push(exp);
        }
    }
    return stack.top();
}

int main()
{
    string prefix,postfix;
    cout << "Enter the postfix expression: \n";
    cin>>postfix;
    cout << "postfix expression: \n"<<postfix<<endl;

    prefix = PostfixToPrefix(postfix);

    cout << "Prefix expression: \n"<<prefix<<endl;
    return 0;
}