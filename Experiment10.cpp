
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int height;
    Node *left,*right;
};

// Height
int height(Node* node){
    return node == NULL ? 0 : node->height;
}

// Maximum
int maxValue(int a,int b){
    return a > b ? a : b;
}

// Create Node
Node* createNode(int key){
    Node* node = new Node;

    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Right Rotation
Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + maxValue(height(y->left),height(y->right));
    x->height = 1 + maxValue(height(x->left),height(x->right));

    return x;
}

// Left Rotation
Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + maxValue(height(x->left),height(x->right));
    y->height = 1 + maxValue(height(y->left),height(y->right));

    return y;
}

// Balance Factor
int getBalance(Node* node){
    if(node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// Insert
Node* insert(Node* node,int key){
    int balance;

    if(node == NULL)
        return createNode(key);

    if(key < node->key)
        node->left = insert(node->left,key);
    else if(key > node->key)
        node->right = insert(node->right,key);
    else
        return node;

    node->height = 1 + maxValue(height(node->left),height(node->right));
    balance = getBalance(node);

    // LL Case
    if(balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR Case
    if(balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR Case
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find Minimum Node
Node* minValueNode(Node* node){
    Node* current = node;

    while(current->left != NULL)
        current = current->left;

    return current;
}

// Delete Node
Node* deleteNode(Node* root,int key){
    Node* temp;
    int balance;

    if(root == NULL)
        return root;

    if(key < root->key)
        root->left = deleteNode(root->left,key);
    else if(key > root->key)
        root->right = deleteNode(root->right,key);
    else{
        if(root->left == NULL || root->right == NULL){
            temp = root->left != NULL ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
            }

            delete temp;
        }
        else{
            temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,temp->key);
        }
    }

    if(root == NULL)
        return root;

    root->height = 1 + maxValue(height(root->left),height(root->right));
    balance = getBalance(root);

    // LL Case
    if(balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR Case
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR Case
    if(balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL Case
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder
void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main
int main(){
    Node* root = NULL;
    int choice,key;

    do{
        cout << "\n--- AVL TREE MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter key: ";
                cin >> key;
                root = insert(root,key);
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root,key);
                break;

            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    }while(choice != 4);

    return 0;
}
