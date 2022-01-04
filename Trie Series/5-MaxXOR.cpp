// Problem Link: https://bit.ly/3C6IHDp
// we need find max xor value with any number from array1 and 
// any number from array2
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
struct Node {

    Node* links[2];     // stores links or references to 0 and 1 bits

    bool hasBit(int bit){

        return links[bit]!=NULL;
    }

    Node* getNode(int bit){

        return links[bit];
    }
    void putNode(int bit,Node* node){

        links[bit] = node;
    }
};

class Trie {

    private: Node* root;
    
    public:
    // constructor to initialize root when trie is created
    Trie(){

        root = new Node();
    }

    void insert(int num){
        
        Node* node = root;      // take reference of root to traverse the trie
        
        /*
        since numbers stored in bits like 00...1 for 1
        32 bits for int 
        we store the bits from start bit to end bit
        */
        for(int i=31;i>=0;i--){
            
            int bit = num>>i & 1;           // get bit at ith index of bits

            if(!node->hasBit(bit)){         // bit not exists

                node->putNode(bit,new Node());  // create node at this bit
            }

            node = node->getNode(bit);      // move to current bit
        }
    }

    int getMaxXOR(int num){

        Node* node = root;
        int maxNum = 0;

        for(int i=31;i>=0;i--){

            int bit =  num>>i & 1;      // get bit at ith index of bits

            // to get xor value 1, we need opposite bit

            if(node->hasBit(1-bit)){         // if opposite bit exists

                // ith index bit of maxNum gets 1
                maxNum = maxNum | (1<<i);    // make ith index bit of maxNum as 1

                node = node->getNode(1-bit);  // move to opposite bit
            }
            else{
                // xor value will be 0
                // no need to change bit since we initized maxNum with zero
                // all bits expect we changed are 0s
                node = node->getNode(bit);      // move to same bit
            }
        }
        return maxNum;
    }

};
int main() {
    fastio();

     
    int n,m,maxXOR = 0;
    cin>>n>>m;
    vector<int> arr1(n,0),arr2(m,0);
    for(int i=0 ;i<n;i++){ 
        cin>>arr1[i];
    }
        
    
    for(int i=0 ;i<m;i++){
        cin>>arr2[i];
    }    

    Trie trie;
    // insert all arr1 elements into trie
    for(auto num:arr1){
        trie.insert(num);
    }


    // for every num in arr2 get maxXOR with arr1
    // find max value in those xor's    
    for(auto num:arr2){

        maxXOR = max(maxXOR,trie.getMaxXOR(num));
    }

    cout<<maxXOR;
    return 0;
}
/*
Output:
7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2
15
*/