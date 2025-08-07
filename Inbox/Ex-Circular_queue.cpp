#include <iostream>
#include "C:\Coding\Lab\Lab_DS\Mylib\cqueue.cpp"
using namespace std;

int main()
{
    CQueue<int> queue(5);

    queue.enqueue(12);
    queue.enqueue(13);
    queue.enqueue(14);
    queue.enqueue(15);
    queue.enqueue(16);

    queue.display();
    
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    
    queue.enqueue(17);
    queue.enqueue(18);
    queue.enqueue(19);
    
    queue.display();
    
    
}