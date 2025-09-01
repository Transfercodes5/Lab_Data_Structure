#include<iostream>
using namespace std;

template <class T>

class Linked_list
{
    struct node
    {
        T data;
        node *next;
    };

    public:

    node *head = nullptr;

    void insertAtBeginning(T value)
    {
        node *newnode = new node;
        newnode->data = value;

        if(head == NULL)
        {
            head = newnode;
            head->next = NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }

        // node *newnode = new node;
        // newnode->data = value;
        // newnode->next = head;
        // head = newnode;
    }

    void insertAtEnd(T value)
    {
        
    }
};
