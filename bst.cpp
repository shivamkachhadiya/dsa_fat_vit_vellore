#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insetBst(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        // right
        root->right = insetBst(root->right, data);
    }
    else
    {
        root->left = insetBst(root->left, data);
    }
    return root;
}

Node *takeinput(Node *root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insetBst(root, data);
        cin >> data;
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);       // 1 Visit left subtree
    cout << root->data << " "; // 2️Visit root
    inorder(root->right);      // 3️Visit right subtree
}
int main()
{
    Node *root = NULL;
    cout << "enter data for create bst" << endl;
    root = takeinput(root);
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    return 0;
}