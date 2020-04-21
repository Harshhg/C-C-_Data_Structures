#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};
struct LinkedListNode
{
    int val;
    LinkedListNode* next;
};

//function to create node of tree.
TreeNode* createNode(int value)
{
    TreeNode *node = new TreeNode;
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//function to create node of linked list.
LinkedListNode* createLinkedListNode(int value)
{
    LinkedListNode* node = new LinkedListNode;
    node->val = value;
    node->next = NULL;
    return node;
}

//function to insert new node at the end of the linked list.
void insertAtEnd(TreeNode* root, int level, vector<LinkedListNode*>& res)
{
    LinkedListNode* temp = res[level];
    while(temp->next)
        temp = temp->next;
  
    temp->next = createLinkedListNode(root->val);
    return;
}

//function to traverse the tree
void dfs(TreeNode* root, int level, vector<LinkedListNode*>& res)
{
    if(!root)
        return;
    
    //if level is not in linked list
    if(res.size()<level+1)
    {
        LinkedListNode* node = createLinkedListNode(root->val);
        res.push_back(node);
    }
    else
       insertAtEnd(root, level, res);
    
    
    dfs(root->left, level+1, res);
    dfs(root->right, level+1, res);
    return;
    
}

vector<LinkedListNode*> createLinkedList(TreeNode *root)
{
  vector<LinkedListNode*> res;
  dfs(root,0, res);
  return res;
}

int main()
{
    // Creating a tree
    /*
                  5
                /   \ 
               4     3
              / \   / \
             6   7 8   9
    
    */
    TreeNode* root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(3);
    root->left->left = createNode(6);
    root->left->right = createNode(7);
    root->right->left = createNode(8);
    root->right->right = createNode(9);
	
	// Done
    vector<LinkedListNode*> res;
    
	res = createLinkedList(root);
	  for(auto it: res)
	  {
	    LinkedListNode* temp = it;
  	    while(temp != NULL)
	      {
	          cout<<temp->val<<"-";
	          temp = temp->next;
	      } 
	    cout<<endl;
	  }
	return 0;
}
