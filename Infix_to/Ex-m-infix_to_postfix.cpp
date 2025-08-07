#include <iostream>
#include <string>
using namespace std;

template <class T>

class Stack
{
    public:

    T* stack;
    int top = -1;
    int size;

    Stack(int s)
    {
        this->size = s;
        stack = new T[size];
    }

    void push(T n)
    {
        if(top<size)
        {
            top = top + 1;
            stack[top] = n;
        }
    }

    T pop()
    {
        if(top>-1)
        {
            top = top -1;
            return stack[top+1];
        }
        else
        {
            return 0;
        }
    }


    T peek()
    {
        if(top<0)
            return 0;
        else
            return stack[top];
    }

    void display()
    {
        for(int i = 0;i<=top;i++)
        {
            cout<<"Element["<<i<<"] : "<<stack[i]<<endl;
        }
    }

    void reverse(Stack &stack2)
    {
        while(!stack2.isempty())
        {
            this->push(stack2.pop());
        }
    }

    bool isempty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isfull()
    {
        if (top == size)
            return true;
        else
            return false;
    }

};

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

    for(int i=0;i<infixeq.length();i++)
    {
        if(isspace(infixeq[i]))
            infixeq.erase(i,1);
    }

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