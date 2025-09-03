#include<iostream>
#include "..\Mylib\SinglyLinkedList.cpp"

int main()
{
    SinglyLinkedList<int> list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtEnd(60);

    list.display();
    cout<<endl;

    // list.insertAtPosition(3, 33);
    list.deleteAtPosition(5);

    // list.display();

    list.deleteAtPosition(5);

    
}