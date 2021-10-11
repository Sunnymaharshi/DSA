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
    stack<Node*> st;
    vector<int> pre_order;
    
    if(root!=nullptr)
        st.push(root);  

    while(!st.empty()){       //root->left->right
        Node* node=st.top();
        st.pop();              
        pre_order.push_back(node->data);
        if(node->right!=nullptr)
            st.push(node->right);
        if(node->left!=nullptr)
            st.push(node->left);  //since stack is last in first out (LIFO) we add left node after right node
    }

    cout<<"Pre Order Traversal:\n";
    for(auto node : pre_order){        
        cout<<node<<" ";
    }

}
/*
Tree:

          1
    2            3
4       5     6      7

Output:
Pre Order Traversal:
1 2 4 5 3 6 7 
*/