#include<iostream>
using namespace std;

template <class T>

class SinglyLinkedList
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

        if(head == nullptr)
        {
            head = newnode;
            head->next = nullptr;
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
        node *newnode = new node;
        newnode->data = value;

        if(head == nullptr)
        {
            head = newnode;
            head->next = nullptr;
        }
        else
        {
            node *temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->next = nullptr;
        }
    }

    void insertAtPosition(int pos, T value)
    {
        node *newnode = new node;
        newnode->data = value;

        if(pos < 0)
            throw out_of_range("Negative Postion is NOT allowed");

        if(pos == 0)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        if(head == nullptr)
            throw out_of_range("List is empty");

        node *temp = head;

        for(int i=0;i<pos-1;i++)
        {
            if(temp->next == nullptr)
            {
                throw out_of_range("Position is out of scope of list");
            }

            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    void deleteAtBeginning()
    {
        if(head == nullptr)
        {
            throw out_of_range("List is Empty");
        }
        else
        {
            if(head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                node *temp = head;
                head = head->next;
                delete temp;
            }
        }

        // if(head == nullptr)
        // {
        //     throw out_of_range("List is Empty");
        // }
        // else
        // {
        //     node *temp = head;
        //     head = head->next;
        //     delete temp;
        // }
    }

    void deleteAtEnd()
    {
        if(head == nullptr)
        {
            throw out_of_range("List is Empty");
        }
        else
        {
            if(head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                node *temp = head;

                while(temp->next->next != nullptr)
                {
                    temp = temp->next;
                }

                delete temp->next;
                temp->next = nullptr;

            }
        }
    }

    void deleteAtPosition(int pos)
    {

        if(head == nullptr)
        {
            throw out_of_range("List is Empty");
        }


        if(pos < 0)
        {
            throw out_of_range("Negative Postion is NOT allowed");
        }

        if(pos == 0)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node *temp = head;

        for(int i=0;i<pos-1;i++)
        {
            temp = temp->next;

            if(temp->next == nullptr)
            {
                throw out_of_range("Position is out of sscope");
            }
        }

        node *temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        node *temp = head;
        int i = 0;

        while (temp != nullptr)
        {
            cout << "Element[" << i << "] : " << temp->data << endl;
            temp = temp->next;
            i++;
        }
}

    ~SinglyLinkedList()
    {
        node *temp = head;
        node *temp2;

        while(temp != nullptr)
        {
            temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }
};
