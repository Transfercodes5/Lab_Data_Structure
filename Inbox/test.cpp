#include<iostream>
#include "C:\Coding\Lab\Lab_DS\Inbox\stack.cpp"
using namespace std;

int main()
{

    string infixeq = "(A + B) * (C + D)";

    cout<<infixeq<<endl;
    
    for(int i=0;i<infixeq.length();i++)
    {
        if(isspace(infixeq[i]))
        {
            infixeq.erase(i,1);
        }
    }

    cout<<infixeq;

}
