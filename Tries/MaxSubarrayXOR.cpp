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
};
Node* root = new Node();
void insert(int n){
    Node* temp = root;
    for(int bit=31; bit>=0; bit-- ){
        int bitval= n & (1<<bit);
        if(temp->contains(bitval)){
            temp = temp->getNext(bitval);
        }
        else{
    
            temp->put(bitval,new Node());
            temp = temp->getNext(bitval);
        }
    }
    temp->value = n;
}
int findMaxXOR(int n){

    Node* temp = root;
    for(int bit=31; bit>=0; bit-- ){
        int bitval= n & (1<<bit);
        if(temp->contains(!bitval)){
            temp = temp->getNext(!bitval);
        }
        else if(temp->contains(bitval)){
            temp = temp->getNext(bitval);
        }
        else
            return INT_MIN;
    }
    return n^temp->value;
}
int maxSubarrayXOR(int arr[], int n){

    int prefixXor = arr[0];
    insert(prefixXor);
    int maxXor = prefixXor;
    for(int i=1; i<n; i++){
        prefixXor = prefixXor ^ arr[i];
        // take full
        maxXor = max(maxXor,prefixXor);
        // remove --> finds max xor when we remove previous prefixes
        maxXor = max(maxXor, findMaxXOR(prefixXor));
        insert(prefixXor); // add prefix to trie
    }
    return maxXor;

}
int main() {


    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"max subarray xor:"<<maxSubarrayXOR(arr,n);
    return 0;
}

/*
Output:
3
1 0 3
max subarray xor:3
*/