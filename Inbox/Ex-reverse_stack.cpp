#include <iostream>
using namespace std;

void push(int *stack,int *top,int n)
{
    if(*top<10)
    {
        *top = *top + 1;
        stack[*top] = n;;
    }
}

int pop(int *stack,int *top)
{
    if(*top>-1)
    {
        *top = *top -1;
        return stack[*top+1];
    }
    else
    {
        return NULL;
    }
}

void reverse(int *stack1,int *top1,int *stack2,int *top2)
{
    while(*top1 != -1)
    {
        push(stack2,top2,pop(stack1,top1));
    }
}

int main()
{
    int stack1[10];
    int stack2[10];
    int top1 = -1;
    int top2 = -1;

    int choice,num;

    push(stack1,&top1,10);
    push(stack1,&top1,12);
    push(stack1,&top1,81);
    push(stack1,&top1,78);
    push(stack1,&top1,32);
    push(stack1,&top1,05);


    cout<<"Printing first stack.................."<<endl;

    for(int i=0;i<=top1;i++)
    {
        cout<<"Element["<<i<<"] : "<<stack1[i]<<endl;
    }

    reverse(stack1,&top1,stack2,&top2);

    cout<<"\nPrinting second stack.................."<<endl;

    for(int i=0;i<=top2;i++)
    {
        cout<<"Element["<<i<<"] : "<<stack2[i]<<endl;
    }
}