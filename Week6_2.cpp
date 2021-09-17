/*
ทำ Binary Tree
Using iterative to insert
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int key)
{
    Node *node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}
void printTree(Node *root, int space)
{
    //ผมพยายามไม่ทำเป็น recursive แต่ไม่รอดครับ
    if (root == nullptr)
        return;

    space += 10;
    printTree(root->left, space);

    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->data;
    
    printTree(root->right, space);
}

void insertIterative(Node *&root, int key)
{
    Node *curr = root;
    Node *parent = nullptr;
    if (root == nullptr)
    {
        root = newNode(key);
        return;
    }
    while (curr != nullptr)
    {
        parent = curr;
        if (key < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (key < parent->data)
    {
        parent->left = newNode(key);
    }
    else
    {
        parent->right = newNode(key);
    }
}

main()
{
    int n;
    cout << "Enter amount of element" << endl;
    cin >> n;

    cout << "Enter data:" << endl;
    int* num = new int[n];
    for(int i=0;i<n;i++)
        cin >> num[i];
    
    Node *root = nullptr;
    for (int i=0;i<n;i++)
        insertIterative(root, num[i]);

    cout << "Binary Tree:" << endl;
    printTree(root, 0);
}