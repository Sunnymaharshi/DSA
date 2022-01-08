// https://leetcode.com/problems/subsets-ii/
#include<iostream>
#include<vector>
#include<algorithm>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
brute force is to segenerate all subsets and store into set or hashmap
*/
void findUniqueSubsets(int ind,vector<int> &arr,vector<int> &subset,vector<vector<int>> &subsets){

    subsets.push_back(subset);      // add subset into subsets

    for(int i=ind;i<arr.size();i++){

        /*  we must take duplicate elements into subset without getting
            duplicate subsets.
            selecting same element again will generate same subset, hence
            we only select element once in a call.
            i!=ind is for if ind and ind-1 are same we can't take 
            ind element into subset.
            hence we take element at first time and ignore it's duplicates
            in a call.
            then we call the function from it's next index.
            for example [1,2,2]
                            
                            recursion tree
                                  0 []                      len=0
                        1 [1]               2 [2]           len=1
                    2 [1,2]                    3 [2,2]      len=2
                3 [1,2,2]                                   len=3

            length of subset increases from top level to bottom level
        */
        if(i!=ind && arr[i]==arr[i-1])  continue;

        subset.emplace_back(arr[i]);    // take current element into subset

        // start finding subsets with current element from it's next index
        findUniqueSubsets(i+1,arr,subset,subsets);  

        subset.pop_back();     // remove current element from subset
    }

}
int32_t main() {
    fastio();
    int n;
    cin>>n;
    vector<int> arr(n,0),subset;
    for(int i=0;i<n;i++)    cin>>arr[i];
    vector<vector<int>> subsets;

    sort(arr.begin(),arr.end()); // sort the array for ease of finding duplicates

    findUniqueSubsets(0,arr,subset,subsets);
    
    for(auto s:subsets){
        for(auto e:s){
            cout<<e<<sp;
        }
        cout<<nl;
    }

    
    return 0;
}
/*
Output:
3
1 2 2
1 
1 2 
1 2 2 
2 
2 2
*/