#include <iostream>
#include <string>
#include <algorithm>
#include "..\Mylib\stack.cpp"
using namespace std;

int precedence(char c)
{
    switch(c)
    {
        case '+': case '-':
            return 1;
        
        case '*': case '/':
            return 2;
        
        case '^':
            return 3;
    }

    return 0;
}

int main()
{
    Stack<char> stack(30);
    Stack<char> stackbuff(20);
    string infixeq;

    cout<<"Enter Infix Equation : ";
    getline(cin,infixeq);

    infixeq.erase(remove_if(infixeq.begin(), infixeq.end(), ::isspace), infixeq.end());

    for(int i=0;i<infixeq.length();i++)
    {
        if(isalpha(infixeq[i]))
        {
            stack.push(infixeq[i]);
        }
        
        else if(infixeq[i] == '(')
        {
            stackbuff.push(infixeq[i]);
        }

        else if(infixeq[i] == ')')
        {
            while(stackbuff.peek() != '(')
            {
                stack.push(stackbuff.pop());
            }
            stackbuff.pop();
        }

        else
        {
            if (stackbuff.isempty())
            {
                stackbuff.push(infixeq[i]);
            }

            else if (precedence(infixeq[i]) > precedence(stackbuff.peek()))
            {
                stackbuff.push(infixeq[i]);
            }

            else if (precedence(infixeq[i]) < precedence(stackbuff.peek()))
            {
                stack.push(stackbuff.pop());
                i = i - 1 ;
            }

            else if (precedence(infixeq[i]) == precedence(stackbuff.peek()))
            {
                if(precedence(stackbuff.peek()) == 1 || precedence(stackbuff.peek()) == 2)
                {
                    stack.push(stackbuff.pop());
                    stackbuff.push(infixeq[i]);
                }

                else
                {
                    stackbuff.push(infixeq[i]);
                }
            }
        }
    }

    while (!stackbuff.isempty())
    {
        stack.push(stackbuff.pop());
    }
    
    cout<<"Postfix Equation : ";
    stackbuff.reverse(stack);
    while (!stackbuff.isempty())
    {
        cout<<stackbuff.pop()<<" ";
    }
}