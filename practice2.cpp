#include<bits/stdc++.h>
using namespace std;
class  Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }

    void push_back(Node*&head,int val){
        Node* newNode = new Node(val);
        if(head == 0){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp -> next = newNode;
    }

      void display(Node* head){
        while(head != NULL){
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    Node* addlists(Node* p1,Node* p2){
        Node* result = NULL;
    Node* tail = NULL;
        int carry = 0;

while (p1 != NULL || p2 != NULL || carry != 0)
{

    int sum = carry;

    if (p1 != NULL)
    {
        sum += p1->data;
        p1 = p1->next;
    }

    if (p2 != NULL)
    {
        sum += p2->data;
        p2 = p2->next;
    }

    carry = sum / 10;

    Node* newNode = new Node(sum % 10);

    if(result == NULL)
            {
                result = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
        }

        return result;
    }
};
int main(){
    List ll;
    Node* p1 = NULL;
    Node* p2 = NULL;
    ll.push_back(p1,2);
    ll.push_back(p1,5);
    ll.push_back(p1,4);

     ll.push_back(p2,2);
    ll.push_back(p2,5);
    ll.push_back(p2,4);

    Node* sum = ll.addlists(p1,p2);

    ll.display(p1);
    ll.display(p2);
    ll.display(sum);
    return 0;
}