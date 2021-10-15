// Time  Complexity O(n*(2^n)) 
// will not work is n is very large
// if there are n numbers, no of subsets will be 2^n
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> findAllSubsets(vector<int> &v, int n){
    vector<vector<int>> ans;
    for(int ss=0; ss<=(1<<n)-1; ss++){      // 0 to 2^n-1
        vector<int> subset;
        for(int bit=0; bit<n; bit++){
            if(ss&(1<<bit)){                // if bit is set add to subset
                subset.emplace_back(v[bit]);
            }
        }
        ans.emplace_back(subset);
    }
    return ans;
}
int main() {

    int n;
    cin>>n;
    vector<int> arr(n,0);
    vector<vector<int>> subsets;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    subsets = findAllSubsets(arr,n);
    cout<<"subsets:\n";
    for(auto subset:subsets){
        if(subset.size()==0)
            continue;
        for(auto i:subset){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}
/*
3
1 2 3
subsets:
1
2
1 2
3
1 3
2 3
1 2 3
*/