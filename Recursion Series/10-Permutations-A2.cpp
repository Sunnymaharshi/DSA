// https://leetcode.com/problems/permutations/
// Approach 2
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
    elements at index less than ind are taken
    elements at right of current index are untaken including current index
    we swap current element with every untaken elements
    we take every untaken element on current index by swaping
    Time Complexity    - O(N! * N)     
    Space Complexity   - O(1)
*/
void permutations(int ind,vector<int> &arr, vector<vector<int>> &perms){

    if(ind==arr.size()){    // reached end of the array
        perms.emplace_back(arr);
        return;
    }
    for(int i=ind;i<arr.size();i++){    // iterate over untaken elements

        swap(arr[ind],arr[i]);          // take arr[i] for ind
        permutations(ind+1,arr,perms);  // take elements for ind+1

        swap(arr[ind],arr[i]);          // do not take arr[i] for ind
    }
}
int32_t main() {
    fastio();
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)    cin>>arr[i];
    vector<vector<int>> perms;
    permutations(0,arr,perms);
    for(auto p:perms){
        for(auto e:p){
            cout<<e<<sp;
        }
        cout<<nl;
    }  


    return 0;
}
/*
Output:
3
1 2 3
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1
*/