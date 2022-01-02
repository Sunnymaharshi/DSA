#include<iostream>
#include<algorithm>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void subsetSums(int ind,int sum,vector<int> &arr,vector<int> &sums){

    if(ind==arr.size()){            // reached end of array
        sums.emplace_back(sum);     // add to sum to sums array
        return;
    }

    // take the ind element into our subset by adding its value to sum variable
    subsetSums(ind+1,sum+arr[ind],arr,sums);    

    // do not take ind element into our subset
    subsetSums(ind+1,sum,arr,sums);
}
int32_t main() {
    fastio();
    int n;
    cin>>n;
    vector<int> arr(n,0),sums;
    for(int i=0;i<n;i++)    cin>>arr[i];
    subsetSums(0,0,arr,sums);
    sort(sums.begin(),sums.end());      // sort the sums
    for(auto s:sums)
        cout<<s<<sp;

    return 0;
}
/*
Output:
3
1 2 3
0 1 2 3 3 4 5 6
*/