#include<iostream>
#include "C:\Coding\Lab\Lab_DS\Mylib\squeue.cpp"
using namespace std;

int main()
{
    SQueue<int> queue(5);

    queue.enqueue(12);
    queue.enqueue(13);
    queue.enqueue(14);
    queue.enqueue(15);
    queue.enqueue(16);

    queue.display();
}