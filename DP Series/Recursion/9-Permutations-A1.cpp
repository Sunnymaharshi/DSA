// https://leetcode.com/problems/permutations/
// Approach 1
#include<iostream>
#include<vector>
#include<map>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
    each time we take an element that is not taken already and call the
    function to take element which are not taken.
    This only works for array with unique elements
    Time Complexity    - O(N! * N)     
    Space Complexity   - O(N) 
*/
void permutations(map<int,bool> &taken,vector<int> &per,vector<vector<int>> &perms){

    if(per.size()==taken.size()){           // permutation is created
        perms.emplace_back(per);            // O(N)
        // we can also remove this return since permutation size is no of
        // elements in the array, if condition in below 
        // for loop will be false for all elements
        return;                            
    }
    for(auto &e:taken){
        if(e.second==false){

            per.emplace_back(e.first);      // take element into permutaion
            e.second=true;                  // mark it as taken
            permutations(taken,per,perms);  

            per.pop_back();                 // remove the element
            e.second=false;                 // mark it as not taken
        }
    } 
}
int32_t main() {
    fastio();
    int n;
    cin>>n;
    map<int,bool> taken;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        taken[k]=false;        
    }
    vector<int> per;
    vector<vector<int>> perms;
    permutations(taken,per,perms);
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