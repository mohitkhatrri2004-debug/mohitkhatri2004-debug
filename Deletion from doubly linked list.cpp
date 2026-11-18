#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

void deleteFromEnd(Node*& head)
{
    // If list is empty
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    // If there is only one node
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    // Move temp to the last node
    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Make the second-last node's next NULL
    temp->prev->next = NULL;

    // Delete the last node
    delete temp;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

int main()
{
    // Creating the list
    Node* head = new Node(10);

    head->next = new Node(20);
    head->next->prev = head;

    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    cout << "Before deletion: ";
    display(head);

    deleteFromEnd(head);

    cout << "After deletion: ";
    display(head);

    return 0;
}