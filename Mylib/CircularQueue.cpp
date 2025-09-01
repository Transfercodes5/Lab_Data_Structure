#include<iostream>
using namespace std;

template <class T>

class CQueue
{
    public:

    T* queue;
    int size;
    int f = -1;
    int r = -1;

    CQueue(int s)
    {
        this->size = s;
        queue = new T[size];
    }

    bool enqueue(T value)
    {
        if (isfull())
        {
            throw out_of_range("Queue is FULL");
        }
        
        if (f == -1)
        {
            f = r = 0;
        }
        else
        {
            r = (r+1)%size;
        }
        
        queue[r] = value;
        return true;
    }
    
    T dequeue()
    {
        if (isempty())
        {
            throw out_of_range("Queue is EMPTY");
        }

        T temp = queue[f];

        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f = (f+1)%size;
        }
        return temp;
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
        int i = f;
        while(true)
        {
            cout<<"Element["<<i<<"] : "<<queue[i]<<endl;
            
            if (i == r)
                break;
            
            i = (i+1)%size;
        }
    }

    bool isempty()
    {
        if (f == -1)
            return true;
        else 
            return false;
    }

    bool isfull()
    {
        if ((r+1)%size == f)
            return true;
        else 
            return false;
    }

};