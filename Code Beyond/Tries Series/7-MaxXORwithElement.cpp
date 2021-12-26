//something wrong in the code!!!
#include<iostream>
#include<vector>
#include<algorithm>
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
bool com(vector<int> a, vector<int> b){
    if(a[1]<b[1])
        return true;
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> queries;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        queries.push_back({l,r,i});
    }

    sort(queries.begin(),queries.end(),com);
    vector<int> ans(n,0);
    int i=0;
    for(auto q:queries){
        int r=q[1];
        while(i<nums.size() && nums[i]<=r){
            insert(nums[i]);
            i++;
        }
        ans[q[2]]=findMaxXOR(q[0]);
    }
    for(auto i:ans)
        cout<<i<<" ";
}