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

string PrefixToPostfix(string prefix)
{
    stack <string> stack;
    for (int i=prefix.length()-1;i>=0;i--)
    {
        string op(1,prefix[i]);
        if (operand(prefix[i]))
            stack.push(op);
        else
        {
            string op1 = stack.top();
            stack.pop();
            string op2 = stack.top();
            stack.pop();
            string exp = op1+op2+op;
            stack.push(exp);
        }
    }
    return stack.top();
}

int main()
{
    string prefix,postfix;
    cout << "Enter the prefix expression: \n";
    cin>>prefix;
    cout << "prefix expression: \n"<<prefix<<endl;

    postfix = PrefixToPostfix(prefix);

    cout << "Postfix expression: \n"<<postfix<<endl;
    return 0;
}