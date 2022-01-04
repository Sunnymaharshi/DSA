// Problem Link: https://bit.ly/2YzYWev
#include<iostream>
#include<vector>
#include<algorithm>
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

int32_t main() {
    fastio();

    int n,q;
    cin>>n>>q;
    vector<int>  arr(n,0);
    vector<vector<int>> queries;
    vector<int> order(q,0);

    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int i=0;i<q;i++){

        int x,a;
        cin>>x>>a;
        // offline queries-store queries including it's index of order
        queries.push_back({a,x,i});    
    }
    
    
    sort(arr.begin(),arr.end());       // sort the array - O(nlogn)

    // sort queries in increasing order of a
    sort(queries.begin(),queries.end());    // O(qlogq)

    Trie trie;
    int ind=0;

    // O(q*32 + N*32)
    for(auto q:queries){

        int a = q[0];
        int x = q[1];
        int i = q[2];

        while(ind<n && arr[ind]<=a){

            // add all numbers <= a into trie
            trie.insert(arr[ind]);
            ind++;
        }
        
        if(ind==0){         // no elements <= a
            order[i] = -1;
        }
        else{
            order[i] = trie.getMaxXOR(x);
        }
    }

    for(auto ans:order){
        cout<<ans<<sp;
    }

    return 0;
}
/*
Output:
5 2
0 1 2 3 4
1 3
5 6
3 7
*/