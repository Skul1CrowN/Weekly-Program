/*
ทำ Binary Tree
Using recursive to insert
*/
#include <iostream>
using namespace std;
class BTree
{
private:
    int data;
    BTree *left;
    BTree *right;

public:
    BTree()
    {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    BTree(int data)
    {
        this->data = data;
        left = right = NULL;
    }
    BTree *insert(BTree *root, int data)
    {
        if (!root)
        {
            return new BTree(data);
        }

        if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        else
        {
            root->left = insert(root->left, data);
        }

        return root;
    }
    void printTree(BTree *root, int space)
    {
        if (root == NULL)
            return;
    
        space += 10;
    
        printTree(root->left, space);
    
        cout << endl;
        for (int i = 10; i < space; i++)
            cout << " ";
        cout << root->data;
    
        printTree(root->right, space);
    }
};

main()
{
    int n;
    cout << "Enter amount of element" << endl;
    cin >> n;

    cout << "Enter data:" << endl;
    int* num = new int[n];
    for(int i=0;i<n;i++)
        cin >> num[i];

    BTree tree,*root = NULL;

    root = tree.insert(root,num[0]);
    for(int i=1;i<n;i++)
        tree.insert(root,num[i]);
    
    cout << "Binary Tree:" << endl;
    tree.printTree(root,0);
}