// https://leetcode.com/problems/combination-sum-ii
// brute-force:subset sum with subsets stored in hashmap or set data structure
#include<iostream>
#include<algorithm>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

/*
instead of selecting and not selecting elements into subsequence,we select subsequences
starting from particular element.
there's no point starting a subsequence with same starting element,
so we ignore duplicate starting elements.
selection of starting element for subsequence occurs at every index, hence all the duplicate elements
are considered in subsequences. ignoring duplicate starting elements, gives us unique subsequences.
Time Complexity: O(2^N * N)
*/

void UniqueCombinations(int ind,int n,int target,vector<int> &arr,vector<int> &com,vector<vector<int>> &combs){


    if(target==0){                     
        combs.emplace_back(com);            // O(N)
        // since all elements are >= 1, so we cannot get combinations with sum as target
        // by further adding elements. hence we end the function
        return;
    }
    for(int i=ind;i<n;i++){ 

        // since arr is sorted, all elements after arr[i] also invalid
        if(arr[i]>target)   break; 

        /*  there's no point of selecting same starting element for our subsequence.
            i>ind is for element at ind won't be ignored if arr[ind-1]==arr[ind] 
            then we'll lose ind element,
            duplicate element can be our starting element in next call.
            this helps in considering all elements into our subsequences.
            for example: 1 1 2 target=4
                                    recursion tree
                                            0 [] t=4
                                  1 [1] t=3           3 [2] t=2
                        2 [1,1] t=2     3 [1,2] t=1
                  3 [1,1,2] t=0


            with i>ind, we won't lose any of duplicate elements for our starting element

        */
        if(i>ind && arr[i]==arr[i-1])   continue;

        com.emplace_back(arr[i]);       // pick the start element

        // subtract target with arr[i] and start selecting subsequence from next index
        UniqueCombinations(i+1,n,target-arr[i],arr,com,combs);

        com.pop_back();                 // remove the start element
    }

}
int32_t main() {
    fastio();
    int n,target;
    cin>>n>>target;
    vector<int> com,arr(n,0);
    for(int i=0;i<n;i++)    cin>>arr[i];
    vector<vector<int>> combs;
    sort(arr.begin(),arr.end());    // sort the array, since we need combinations in sorted order
    UniqueCombinations(0,n,target,arr,com,combs);  
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
5 5
2 5 2 1 2
1 2 2 
5
*/