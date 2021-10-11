#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
void InOrder(Node* root){      // left->root->right
    if(root!=nullptr){
        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }
}
void PreOrder(Node* root){      // root->left->right
    if(root!=nullptr){
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
    
    
}  
void PostOrder(Node* root){      // left->right->root
    if(root!=nullptr){
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }
    
}
int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    cout<<"InOrder Traversal:";
    InOrder(root);
    cout<<endl;
    cout<<"PreOrder Traversal:";
    PreOrder(root);
    cout<<endl;
    cout<<"PostOrder Traversal:";
    PostOrder(root);
    cout<<endl;


}
/*
Tree:

            1
    2              3
4       5      6       7

Output:
InOrder Traversal:4 2 5 1 6 3 7   
PreOrder Traversal:1 2 4 5 3 6 7  
PostOrder Traversal:4 5 2 6 7 3 1
*/