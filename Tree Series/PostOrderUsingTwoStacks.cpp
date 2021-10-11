//recursive functions internally use stack data structure
#include<iostream>
#include<vector>
#include<stack>
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
int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    stack<Node*> st1,st2;
    vector<int> post_order;
    
    Node* node=root;
    if(node!=nullptr)
        st1.push(node);
    while(!st1.empty()){
        node=st1.top();
        st1.pop();
        st2.push(node);                //push root into st2

        if(node->left!=nullptr)
            st1.push(node->left);      //traverse left
        if(node->right!=nullptr)
            st1.push(node->right);     //traverse right

    }
    //st2 contains post order in reverse
    while(!st2.empty()){
        post_order.push_back(st2.top()->data);
        st2.pop();
    }

    cout<<"Post Order Traversal:\n";
    for(auto i: post_order)
        cout<<i<<" ";


}
/*
Tree:

          1
    2            3
4       5     6      7

Output:
Post Order Traversal:
4 5 2 6 7 3 1
*/