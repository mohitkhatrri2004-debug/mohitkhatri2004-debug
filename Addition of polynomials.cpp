#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int coef, exp;
    Node* next;

    Node(int c,int e){
        coef = c;
        exp = e;
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

    void push_back(Node*& head, int coeff, int exp) {
    if (coeff == 0) return;

    Node* newNode = new Node(coeff, exp);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

    Node* addpolymers(Node* p1 , Node* p2){
        Node* result = NULL;
        while(p1 != NULL && p2 != NULL){
        if(p1 -> exp > p2 -> exp){
            push_back(result , p1->coef , p1->exp);
            p1 = p1->next;
        }else if(p2->exp > p1->exp){
            push_back(result,p2->coef,p2->exp);
            p2 = p2->next;
        }else{
            push_back(result,p1->coef + p2->coef , p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while(p1 != NULL){
        push_back(result,p1->coef,p1->exp);
        p1 = p1->next;
    }
    while(p2 != NULL){
        push_back(result,p2->coef,p2->exp);
        p2 = p1->next;
    }
    return result;
}
    
    void display(Node* head) {
    while (head != nullptr) {
        cout << head->coef << "x^" << head->exp;

        if (head->next != nullptr)
            cout << " + ";

        head = head->next;
    }
    cout << endl;
}
};
int main(){
    List ll;
    Node* p1 = NULL;
    Node* p2 = NULL;
    ll.push_back(p1,2,5);
    ll.push_back(p1,3,2);
    ll.push_back(p1,4,1);

    ll.push_back(p2,6,5);
    ll.push_back(p2,9,2);
    ll.push_back(p2,7,1);

    Node* sum = ll.addpolymers(p1 , p2);
    ll.addpolymers(p1 , p2);
    ll.display(p1);
    ll.display(p2);
    ll.display(sum);
    return 0;
}