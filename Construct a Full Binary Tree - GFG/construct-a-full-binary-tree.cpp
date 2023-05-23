//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        Node * root = new Node(pre[0]);
        root->left = NULL;
        root->right = NULL;
        make(&root,preMirror,pre,0,size-1,0,size-1);
        return root;
    }
    void make(Node ** root,int m[],int p[],int i,int j,int im,int jm){
        if(*root==NULL){
            *root = new Node(p[i]);
            (*root)->left=NULL;
            (*root)->right=NULL;
        }
        else (*root)->data = p[i];
        // cout<<root->data<<" ";
        if(i==j){
            return;
        }
        int l = p[i+1];
        int r = m[im+1];
        int indl,indr;
        for(int k=i;k<=j;k++){
            if(p[k]==r){
                indr = k;
                break;
            }
        }
        for(int k=im;k<=jm;k++){
            if(m[k]==l){
                indl = k;
                break;
            }
        }
        make(&((*root)->left),m,p,i+1,indr-1,indl,jm);
        make(&((*root)->right),m,p,indr,j,im+1,indl-1);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends