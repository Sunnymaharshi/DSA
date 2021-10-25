// print only one subset with sum divisible by k
#include<iostream>
#include<vector>
using namespace std;

bool SubsetWithSumDivByK(int i, int k, int sum, vector<int> &arr, vector<int> &subset){

    if(i==arr.size()){
        if(subset.size()!=0 && sum%k==0){   
            for(auto e:subset)
                cout<<e<<" ";
            cout<<endl;
            return true;                 // if you found subset return true
        }

        return false;                   // if not found retrun false
    }

    subset.push_back(arr[i]);           // add element to subset
    sum += arr[i];                      // add element to sum
    
    if(SubsetWithSumDivByK(i+1,k,sum,arr,subset)==true) // if we got valid subset, we don't do further calls
        return true;

    subset.pop_back();                  // remove element from subset
    sum -= arr[i];                      // subtract element from sum
    if(SubsetWithSumDivByK(i+1,k,sum,arr,subset)==true)
        return true;
    
    return false;                       // if we do not found subset with element and with element
    
}

int32_t main() {

    int n,k;
    cin>>n;
    vector<int> arr(n,0), subset;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    if(SubsetWithSumDivByK(0,k,0,arr,subset)==false)
        cout<<"No Subset Found";
    return 0;
}
/*
Output:
*/