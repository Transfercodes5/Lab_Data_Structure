#include<iostream>
using namespace std;

template <class T>

class SQueue
{
    public:

    T* queue;
    int size;
    int f = -1;
    int r = -1;

    SQueue(int s)
    {
        this->size = s;
        queue = new T[size];
    }

    bool enqueue(T value)
    {
        if(isfull())
        {
            throw out_of_range("Queue is Full");
        }

        if(isempty())
        {
            f = 0;
        }

        r = r+1;
        queue[r] = value;
        return true;
    }

    T dequeue()
    {
        if(!isempty())
        {
            f = f+1;
            return queue[f-1];
        }
        else
        {
            throw out_of_range("Queue is EMPTY");
        }
    }

    T peek()
    {
        if(!isempty())
        {
            return queue[f];
        }
        else
        {
            throw out_of_range("Queue is EMPTY");
        }
    }

    void display()
    {
        for(int i=f;i<=r;i++)
        {
            cout<<"Element["<<i<<"] : "<<queue[i]<<endl;
        }
    }

    bool isempty()
    {
        if(f > r || f == -1)
            return true;
        else
            return false;
    }

    bool isfull()
    {
        if(r == (size-1))
            return true;
        else
            return false;
    }

    ~SQueue()
    {
        delete[] queue;
    }
};