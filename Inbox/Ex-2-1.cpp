#include <iostream>
using namespace std;

int top = -1;

void push(int *stack,int n)
{
    if(top<10)
    {
        top = top + 1;
        stack[top] = n;
        cout<<"\nElement has been Pushed.................."<<endl;
    }
    else
    {
        cout<<"\nStack overflow Element has not been pushed................"<<endl;
    }
}

void pop(int *stack)
{
    if(top>-1)
    {
        top = top -1;
        cout<<"\nElement "<<stack[top+1]<<" has been popped.............."<<endl;
    }
    else
    {
        cout<<"\nStack Underflow stack is empty......................."<<endl;
    }
}

void peek(int *stack)
{
    cout<<"\nTop most element is "<<stack[top]<<" .................."<<endl;
}

int main()
{
    int stack[10];
    int choice,num;

    do
    {
        cout<<"Enter 1 for PUSH"<<endl;
        cout<<"Enter 2 for POP"<<endl;
        cout<<"Enter 3 for PEEK"<<endl;
        cout<<"Enter 4 for DISPLAY"<<endl;

        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter number to push into stack : ";
                cin>>num;

                push(stack,num);
                break;
                
            case 2:
                pop(stack);
                break;
                
            case 3:
                peek(stack);
                break;
                
            case 4:
                for(int i = 0;i<=top;i++)
                {
                    cout<<"Element["<<i<<"] : "<<stack[i]<<endl;
                }
                break;

            default:
                cout<<"Wrong input please try again...................";
                break;
        }

        cout<<"\n\bEnter 9 to continue : ";
        cin>>choice;

    }while(choice == 9);

    for(int i = 0;i<=top;i++)
    {
        cout<<"Element["<<i<<"] : "<<stack[i]<<endl;
    }

}