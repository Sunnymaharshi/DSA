// here we can select element any no of times
#include<iostream>
#include<vector>
using namespace std;
#define int long long

void findSubsetsSumWithInfy(int i,int sum,vector<int> &arr, vector<int> &subset){

    if(i==arr.size()){            // after traversing all array elements
          
        if(subset.size()!=0 && sum==0){  
            for(auto ele:subset){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
        return;                     // end the function
    }

    if(arr[i]<=sum){               // if value less than sum we can include in the subset

        subset.push_back(arr[i]);   
        // stay at same index, since we can take element any number of times
        findSubsetsSumWithInfy(i,sum-arr[i],arr,subset);
        subset.pop_back();
    }

    findSubsetsSumWithInfy(i+1,sum,arr,subset);    // do not include the element in subset
   
}
int countfindSubsetsSumWithInfy(int i,int sum,vector<int> &arr){

    if(sum==0)  return 1; // this reduces no of function calls, without this line also we get correct answer

    if(i==arr.size()){            // after traversing all array elements
          
        if(sum==0){  
            return 1;           // valid
        }
        return 0;               // invalid
    }
    int ans=0;
    if(arr[i]<=sum){               // if value less than sum we can include in the subset
 
        // stay at same index, since we can take element any number of times
        ans += countfindSubsetsSumWithInfy(i,sum-arr[i],arr);
    }

    ans += countfindSubsetsSumWithInfy(i+1,sum,arr);    // do not include the element in subset

    return ans;
   
}
int32_t main() {

    int n,k;
    cin>>n;
    vector<int> arr(n,0), subset;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    cout<<"no of subsets with sum is "<<k<<":"<<countfindSubsetsSumWithInfy(0,k,arr);
    cout<<"\nsubsets who sum is "<<k<<endl;
    findSubsetsSumWithInfy(0,k,arr,subset);
    return 0;
}
/*
Output:
3
1 2 3
5
no of subsets with sum is 5:5
subsets who sum is 5
1 1 1 1 1
1 1 1 2
1 1 3
1 2 2
2 3
*/