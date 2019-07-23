/*
	Insertion in Binary Tree
*/
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int num;
    Node* left;
    Node* right;
};

Node* getNode(int key,int num){
    Node* node= new Node();
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->num=num;
    return node;
}

Node* insert(Node* root, int key,int num){
    if(root==NULL)
        return NULL;
    if ((2*root->num)==num)
        root->left=getNode(key,num);
    else if ((2*root->num)+1 == num)
        root->right=getNode(key,num);
    else{
        root->left=insert(root->left,key,num);
        root->right=insert(root->right,key,num);
    }
    return root;
}

void inorder(Node* root){
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
    return;
}

int main()
{
    int x,n;
    cin>>n;
    Node* root= new Node();
    int i=1;
    while(n--)
    {
        cin>>x;
        root=insert(root,x,i);
        i++;
    }
    inorder(root);
    return 0;
}
