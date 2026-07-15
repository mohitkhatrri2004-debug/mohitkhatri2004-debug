#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int coef,exp;
    Node* next;

    Node(int c,int e){
        coef = c;
        exp = e;
        next = NULL;
    }
};
class  List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }

    void push_back(Node* &head,int coef,int exp){

        Node* newNode = new Node(coef , exp);

        if(head == NULL){
            head =  newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp -> next = newNode;
    }

    Node* multiplication(Node* p1, Node* p2){
        Node* result = NULL;

        Node* first = p1;

        while(first != NULL){
            Node* second = p2;

            while(second != NULL){
                int newcoef = first->coef * second->coef;
                int newexp = first->exp + second->exp;

                push_back(result,newcoef,newexp);
                second = second->next;
            }
            first = first->next;
        }
        return result;
    }
    void display(Node* head){
        while(head != NULL){
            cout << head->coef << "x^" << head->exp << " ";

            if(head->next != NULL){
                cout << " + ";
            }
            head = head->next;
        }
        cout << endl;
    }

};
int main(){
    List ll;
    Node* p1 = NULL;
    Node* p2 = NULL;

    ll.push_back(p1,2,4);
    ll.push_back(p1,3,3);
    ll.push_back(p1,4,2);

    ll.push_back(p2,2,4);
    ll.push_back(p2,3,3);
    ll.push_back(p2,4,2);

    Node* Multiply = ll.multiplication(p1,p2);
    ll.display(p1);
     ll.display(p2);
      ll.display(Multiply);
    return 0;
}