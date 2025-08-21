# include <iostream>
#include <stack>
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

string InfixToPostfix(stack <char> stack, string infix)
{
    string postfix;
    for (int i=0;i<infix.length();i++)
    {
        if ((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z'))
        {
            postfix += infix[i];
        }
        else if (infix[i]=='(')
        {
            stack.push(infix[i]);
        }
        else if (infix[i]==')')
        {
            while (stack.top()!='(')
            {
                postfix += stack.top();
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
                    stack.push(infix[i]);
                }
                else
                {
                    while((!stack.empty())&&(precedence(infix[i])<=precedence(stack.top())))
                    {
                        postfix +=stack.top();
                        stack.pop();
                    }
                    stack.push(infix[i]);
                }
            }
        }
    }
    while(!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

int main ()
{
    string infix;
    string postfix;
    cout<<"Enter the infix expression :\n";
    cin>>infix;
    stack <char> s;
    cout <<"Infix expression:\n"<<infix<<endl;
    string p = InfixToPostfix(s,infix);
    cout << "postfix expression:\n"<<p<<endl;
    return 0;
}