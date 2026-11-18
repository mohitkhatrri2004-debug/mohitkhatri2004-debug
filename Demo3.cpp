
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// 1. Insertion
Node* insert(Node* root, int value) {

    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// 2. Searching
bool search(Node* root, int key) {

    if (root == NULL) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    if (key < root->data) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

// Find minimum value node
Node* findMin(Node* root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// 3. Deletion
Node* deleteNode(Node* root, int key) {

    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// 4. Inorder Traversal
void inorder(Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Main function
int main() {

    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n\n--- BST OPERATIONS ---";
        cout << "\n1. Insertion";
        cout << "\n2. Searching";
        cout << "\n3. Deletion";
        cout << "\n4. Inorder Traversal";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;

                root = insert(root, value);
                cout << "Node inserted successfully!";
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;

                if (search(root, value)) {
                    cout << "Value found!";
                }
                else {
                    cout << "Value not found!";
                }
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;

                root = deleteNode(root, value);
                cout << "Deletion operation completed!";
                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                break;

            case 5:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}
