#include<iostream>
#include<vector>
#include<queue>
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

void levelOrder(Node* root, vector<vector<int>> &ans){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int level_size=q.size();
        vector<int> level;             // stores nodes of current level
        for(int i=0;i<level_size;i++){
            Node* n=q.front();
            q.pop();                    
            level.emplace_back(n->data);
            if(n->left!=nullptr)
                q.push(n->left);
            if(n->right!=nullptr)
                q.push(n->right);
        }
        ans.emplace_back(level);
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
    vector<vector<int>> ans;
    levelOrder(root,ans);
    cout<<"Level Order Traversal:\n";
    for(auto v:ans){
        for(auto node:v){
            cout<<node<<" ";
        }
        cout<<endl;
    }

}
/*
Tree:

          1
    2            3
4       5     6      7

Output:
Level Order Traversal:
1
2 3
4 5 6 7
*/