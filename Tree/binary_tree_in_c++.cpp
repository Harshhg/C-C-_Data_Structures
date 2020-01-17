#include <iostream>
using namespace std;
struct Treenode             // creating a node structure
{
    int val;
    Treenode* left;
    Treenode* right;
};
Treenode* newNode(int val)      // function to initialize a node with value.  Function return type is struct node.
{
    Treenode* node = new Treenode;     //creating a node of struct type and allocating memory to it.
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void inorder(Treenode* root)        // function to print the inorder traversal of the tree
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main() 
{
 Treenode* root = newNode(10);      //creating a root node and initializing.
 root->left = newNode(5);
 root->right =  newNode(7);
 root->left->left = newNode(3);
 root->left->right =  newNode(4);
 inorder(root);
}
