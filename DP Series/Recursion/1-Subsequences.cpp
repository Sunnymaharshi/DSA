#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void subsequence(int i,int n,vector<int> &arr,vector<int> &sub){
    if(i==n){       // reached end of the array

        for(auto ele:sub){
            cout<<ele<<sp;
        }
        cout<<nl;
        return;     // end the function
    }

    // at each index we have 2 choices, take and do not take that element
    // time complexity - O(2^N)

    sub.emplace_back(arr[i]);       // take ith element into subsequence
    subsequence(i+1,n,arr,sub);     // subsequence with ith element
    sub.pop_back();                 // remove ith element        
    subsequence(i+1,n,arr,sub);     // subsequence without ith element
}

int32_t main() {
    fastio();
    int n;
    cin>>n;
    vector<int> arr(n,0),sub;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    subsequence(0,n,arr,sub);

    return 0;
}
/*
Output:
3
1 2 3
1 2 3 
1 2 
1 3 
1 
2 3 
2 
3
*/