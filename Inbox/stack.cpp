#include<iostream>
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