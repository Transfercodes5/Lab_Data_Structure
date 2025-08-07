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
        if(!isfull())
        {
            top = top + 1;
            stack[top] = n;
        }
        else
        {
            throw out_of_range("Stack is FULL");
        }
    }

    T pop()
    {
        if(!isempty())
        {
            top = top -1;
            return stack[top+1];
        }
        else
        {
            throw out_of_range("Stack is EMPTY");
        }
    }


    T peek()
    {
        if(top<0)
            throw out_of_range("Stack is EMPTY");
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
        if (top == (size-1))
            return true;
        else
            return false;
    }

    ~Stack() 
    {
        delete[] stack;
    }


};