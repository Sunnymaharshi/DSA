#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
let 1 2 3 4     17th position permutation?
it has 4!=24 permutations
16th index
1 [2,3,4]   3!=6 permutations starts with 1     (0-5) indexes  
2 [1,3,4]   3!=6 permutations starts with 2     (6-11) indexes      
3 [1,2,4]   3!=6 permutations starts with 3     (12-17) indexes     
4 [1,2,3]   3!=6 permutations starts with 4     (18-23) indexes     
since every block contains 6 permutations
16/6=2, 2nd indexed block, permutation starts 3
16%6 = 4, we need to find 4th permutation in [1,2,4]

1 [2,4]     2!=2 permutations starts with 1     (0-1) indexes
2 [1,4]     2!=2 permutations starts with 2     (2-3) indexes
4 [1,2]     2!=2 permutations starts with 4     (4-5) indexes
since every block contains 2 permutations
4/2 = 2, 2nd indexed block, permutation starts with 4
4%2 = 0, we need to find 0th permutation in [1,2]   

1 [2]       1!=1 permutations starts with 1     (0-0)
2 [1]       1!=1 permutations starts with 2     (1-1)
since every block contains 1 permutations
0/1 = 0, 0th indexed block, permutation starts  with 1
0%1 = 0, we need to find 0th permutation in [2]

2 []        0!=1 1 permutation starts with 2     (0-0)

Time Complexity - O(N*N)
Space Complexity - O(N)
*/

int32_t main() {
    fastio();
    int n,k,fact=1,startsWith;
    vector<int> nums;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        fact *= i;                  // fact has (n-1)!
        nums.push_back(i);
    }
    nums.push_back(n);              // add nth number
    string ans="";
    k = k-1;                        // 0 based index

    while(true){

        startsWith = nums[k/fact];
        ans = ans + to_string(startsWith);
        nums.erase(nums.begin()+ k/fact);

        if(nums.size()==0){         // permutation completed
            break;
        }

        k = k%fact;                 // kth permutation in remaining elements

        fact = fact/nums.size();    // (n-1)!, since array size reduced

    }
    cout<<ans;
    
    return 0;
}
/*
Output:
4 17
3412
*/