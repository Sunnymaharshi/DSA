// something wrong in the code!!!
#include<iostream>
using namespace std;
struct Node
{
    Node* arr[2];
    int value;
    bool contains(int bit){

        return (arr[bit] != NULL);
    }
    void put(int bit, Node* node){
        arr[bit] = node;
    }
    Node* getNext(int bit){
        return arr[bit];
    }
    void setVal(int v){
        value = v;
    }
    int getVal(){
        return value;
    }
};
Node* root = new Node();
void insert(int n){
    Node* temp = root;
    for(int bit=31; bit>=0; bit-- ){
        int bitval= (n & (1<<bit));
        if(temp->contains(bitval)){
            temp = temp->getNext(bitval);
        }
        else{
            Node* newNode = new Node();
            temp->put(bitval, newNode);
            temp = temp->getNext(bitval);
        }
   }
    temp->setVal(n);
}
int findMinXOR(int n){

    Node* temp = root;
    for(int bit=31; bit>=0; bit-- ){
        int bitval= n & (1<<bit);
        if(temp->contains(bitval)){
            temp = temp->getNext(bitval);
        }
        else if(temp->contains(!bitval)){
            temp = temp->getNext(!bitval);
        }
        else{

            return INT_MAX;
        }
    }

    return (n ^ temp->getVal());
}
int solve(int arr[], int n){

    int minXOR = arr[0]^arr[1];
    insert(arr[0]);
    for(int i=1; i<n; i++){
        //cout<<findMinXOR(arr[i])<<" v"<<arr[i]<<endl;
        minXOR = min(minXOR, findMinXOR(arr[i]));
        insert(arr[i]);
    }

    return minXOR;
}
int main() {

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"min xor:"<<solve(arr,n);
    return 0;
}
/*
Output:
4      
9 5 3 3
min xor:0
*/