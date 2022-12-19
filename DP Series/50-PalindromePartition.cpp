// Problem Link: https://bit.ly/3jNRzqX
#include<iostream>
#include<vector>
#include<limits.h>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

// if we make n-1 partitions, then every substring is palindrome of length 1
// find minimum partitions to make all substrings palindrome
// Front Partitioning

bool isPalindrome(int i, int j, string &str){
    while(i<j){
        if(str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int minPartitions(int i, int n, string &str, vector<int> &dp){

    // no partitions
    if(i==n) return 0;

    // if already calculated
    if(dp[i]!=-1) return dp[i];

    int minCost = INT_MAX;

    for(int j=i;j<n;j++){

        // if string upto j is palindrome, we can make a partition
        if(isPalindrome(i,j,str)){

            int cost = 1 + minPartitions(j+1,n,str,dp);
            minCost = min(minCost,cost);
        }
    }

    return minCost;
}

int minPartitions_tabu(int n, string &str){

    vector<int> dp(n+1,0);

    dp[n] = 0;

    for(int i=n-1;i>=0;i--){

        int minCost = INT_MAX;

        for(int j=i;j<n;j++){

            if(isPalindrome(i,j,str)){

                int cost = 1 + dp[j+1];
                minCost = min(minCost,cost);
            }
        }

        dp[i] = minCost;
    }
    
    // this will also make partition after last character, remove one
    return dp[0] - 1;
}
int main() {
    fastio();

    string str;
    cin>>str;
    int n = str.size();
    vector<int> dp(n,-1);

    // this will also make partition after last character, remove one
    // cout<<minPartitions(0,n,str,dp) - 1;
    cout<<minPartitions_tabu(n,str);

    return 0;
}

/*
Output:
BABABCBADCEDE
4
*/