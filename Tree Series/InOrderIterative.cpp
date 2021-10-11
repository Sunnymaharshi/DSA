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
    vector<int> in_order;
    
    Node* node=root;

    while(true){       
        if(node!=nullptr){
            st.push(node);
            node=node->left;                 //traverse left
        }
        else{
            if(st.empty())  break;
            node=st.top();
            st.pop();
            in_order.push_back(node->data);  //root
            node=node->right;                //traverse right            
        }
    }

    cout<<"Pre Order Traversal:\n";
    for(auto node : in_order){        
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
4 2 5 1 6 3 7 
*/