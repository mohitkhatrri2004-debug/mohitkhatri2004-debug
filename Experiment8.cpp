#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

// Create Node
Node* createNode(int key)
{
    Node* newNode = new Node;

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insertion
Node* insert(Node* root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Searching
Node* search(Node* root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// Find Minimum Node
Node* findMin(Node* root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// Deletion
Node* deleteNode(Node* root, int key)
{
    Node* temp;

    if (root == NULL)
        return NULL;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL)
        {
            temp = root->left;
            delete root;
            return temp;
        }

        temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main Function
int main()
{
    Node* root = NULL;
    Node* result;
    int choice, key;

    do
    {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                root = insert(root, key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;

                result = search(root, key);

                if (result == NULL)
                    cout << "Key not found.\n";
                else
                    cout << "Key found.\n";
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
