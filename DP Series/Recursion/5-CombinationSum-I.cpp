// https://leetcode.com/problems/combination-sum/
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void findCombinations(int ind,int n,int target,vector<int> &arr,vector<int> &com, vector<vector<int>> &combs){
    if(ind==n){             
        if(target==0){      // found combination
            combs.emplace_back(com);
        }
        return;             // end the function
    }

    if(arr[ind]<=target){     // valid element to take 
        com.push_back(arr[ind]);        // pick the element

        findCombinations(ind,n,target-arr[ind],arr,com,combs);  
        // stay on same index, so that we can take same element again if valid

        com.pop_back();     // remove the element from combination
    }

    findCombinations(ind+1,n,target,arr,com,combs);
    // do not pick the element,both valid and invalid

}
int32_t main() {
    fastio();
    int n,target;
    cin>>n>>target;
    vector<int> com,arr(n,0);
    for(int i=0;i<n;i++)    cin>>arr[i];
    vector<vector<int>> combs;
    findCombinations(0,n,target,arr,com,combs);  
    for(auto c:combs){
        for(auto e:c){
            cout<<e<<sp;
        }
        cout<<nl;
    }
    return 0;
}
/*
Output:
3 8
2 3 5
2 2 2 2 
2 3 3 
3 5
*/