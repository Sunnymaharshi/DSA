// Time Complexity - O(2^N * N)
// N is for printing subset
#include<iostream>
#include<vector>
using namespace std;
#define int long long

void findAllSubsets(int i, vector<int> &arr, vector<int> &subset, vector<vector<int>> &subsets){

    if(i==arr.size()){            // after traversing all array elements, add subset to subsets
        subsets.push_back(subset);
        return;                     // end the function
    }
    subset.push_back(arr[i]);  // add ith element to subset
    findAllSubsets(i+1,arr,subset,subsets);   // find subsets which have ith element

    subset.pop_back();           // do not add ith element in the subset
    findAllSubsets(i+1,arr,subset,subsets);  // find subsets which don't have ith element
}
int32_t main() {

    int n;
    cin>>n;
    vector<int> arr(n,0), subset;
    vector<vector<int>> subsets;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"subsets:\n";
    findAllSubsets(0,arr,subset,subsets);
    for(auto sub:subsets){
        for(auto i:sub){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}
/*
Output:
3
5 6 7
subsets:
5 6 7
5 6
5 7
5
6 7
6
7

*/