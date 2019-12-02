#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int key)
{
    struct node* temp = new node;
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void inorder(struct node* root)
{
    if (!root)
        return;
    inorder(root->left);     
    cout<<root->data<<"-";
    inorder(root->right);
        
        
}
int main()
{
    struct node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    inorder(root);
}
