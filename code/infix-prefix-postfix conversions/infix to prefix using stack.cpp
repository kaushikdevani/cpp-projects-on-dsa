# include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


bool isOperator(char c)
{
    if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    else 
        return false;
}

int precedence(char c)
{
    if (c=='+'||c=='-')
        return 1;
    else if (c=='*'||c=='/')
        return 2;
    else if (c=='^')
        return 3;
    else 
        return -1;
}

string InfixToPrefix(stack <char> stack, string infix)
{
    reverse(infix.begin(),infix.end());
    string prefix;

    for ( int i=0 ; i<infix.length();i++)
    {
        if ((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z'))
        {
            prefix += infix[i];
        }
        else if (infix[i]==')')
        {
            stack.push(infix[i]);
        }
        else if (infix[i]=='(')
        {
            while (stack.top()!=')')
            {
                prefix += stack.top();
                stack.pop();
            }    
            stack.pop(); 
        }
        else if(isOperator(infix[i]))
        {
            if(stack.empty())
                stack.push(infix[i]);
            else
            {
                if (precedence(infix[i])>precedence(stack.top()))
                    stack.push(infix[i]);
                else if ((precedence(infix[i])==precedence(stack.top())) && infix[i]=='^')
                {
                    prefix += stack.top();
                }
                else if ((precedence(infix[i])==precedence(stack.top())))
                    stack.push(infix[i]);
                else
                {
                    while ((!stack.empty())&&(precedence(infix[i])<precedence(stack.top())))
                    {
                        prefix +=stack.top();
                        stack.pop();
                    }
                    stack.push(infix[i]);
                }

            }
        }

    }

    while(!stack.empty())
    {
        prefix+=stack.top();
        stack.pop();
    }

    reverse(prefix.begin(),prefix.end());
    return prefix;
}

int main ()
{
    string infix;
    string prefix;
    cout<<"Enter the infix expression :\n";
    cin>>infix;
    stack <char> s;
    cout <<"Infix expression:\n"<<infix<<endl;
    prefix = InfixToPrefix(s,infix);
    cout << "prefix expression:\n"<<prefix<<endl;

    return 0;
}