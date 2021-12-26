#include<iostream>
#include<vector>
using namespace std;
#define int long long
// recursive function - high chances of getting stackoverflow error
// Time Complexity - O(2^N)
int fibo(int n){
    
    if(n<=1)        // 0th and 1st fibonacci numbers are 0,1 
        return n;
    
    return fibo(n-1) + fibo(n-2); // adding previous two fibonacci numbers 
    // above two calls will be executed separately and their sum is returned
}


// memoization dp  - very less chance of stackoverflow error
// Time Complexity O(N)
// Space Complexity O(N)
// it is used only when there is overlapping of function calls occurs
int fiboWithMemo(int n, int memo[]){

    if(memo[n]!=-1)         // nth fibo is already computed return it
        return memo[n]; 
    
    // store result before returning it

    if(n<=1)        // 0th and 1st fibonacci numbers are 0,1 
        return memo[n]=n;    
    
    return memo[n]= fiboWithMemo(n-1,memo) + fiboWithMemo(n-2,memo); 
}

// iterative dp - no stackoverflow error
// Time Complexity O(N)
// Space Complexity O(N)
void fiboWithIterative(int arr[],int n){
    
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
}
int32_t main() {

    int T;
    cin>>T;
    int memo[1000];
    for(int i=0;i<1000;i++)
        memo[i]=-1;
    int dp[1000];
    fiboWithIterative(dp,1000);
    while(T--){

        int n;
        cin>>n;
        //cout<<n<<"th fibonacci number:"<<fibo(n)<<endl;
        //cout<<n<<"th fibonacci number:"<<fiboWithMemo(n,memo)<<endl;
        cout<<n<<"th fibonacci number:"<<dp[n]<<endl;
    }
    
    return 0;
}
/*
Output:
3
10
10th fibonacci number:55
16
16th fibonacci number:987
20
20th fibonacci number:6765
*/