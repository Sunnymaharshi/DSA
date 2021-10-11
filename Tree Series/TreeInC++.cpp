#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){                //constructor
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

}
/*
Tree:

          1
    2            3
4       5     6      7

*/