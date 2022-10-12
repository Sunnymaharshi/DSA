// Problem Link: https://bit.ly/3rWLMnC
#include<iostream>
#include<vector>
#include<algorithm>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// cost is len of stick you are cutting
// cut the stick at given places in any order

int minCost_memo(int i, int j, vector<int> &cuts,vector<vector<int>> &dp){

    if(i>j) return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int min_cost = INT32_MAX;

    for(int ind=i; ind<=j; ind++){

        int cost = cuts[j+1] - cuts[i-1];           // len of stick you are cutting

        // add cost of left and right sub sticks
        cost += minCost_memo(i,ind-1,cuts,dp) + minCost_memo(ind+1,j,cuts,dp);

        min_cost = min(min_cost,cost);            
    }
    return dp[i][j]=min_cost;
}

int minCost_tabu(int n,int c, vector<int> &cuts){

    vector<vector<int>> dp(c+2,vector<int>(c+2,0));

    for(int i=c; i>=1; i--){

        for(int j=1;j<=c;j++){

            if(i>j) continue;

            int min_cost = INT32_MAX;
            for(int ind =i; ind<=j; ind++){

                int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                
                min_cost = min(min_cost,cost);
            }

            dp[i][j] = min_cost;
        }
    }
    return dp[1][c];
}

int main() {
    fastio();

    int n,c;
    cin>>n>>c;
    vector<int> cuts(c);

    for(int i=0;i<c;i++)
        cin>>cuts[i];
    

    // add 0 and size to cuts to calculate length easily
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);

    /*
        1 3 4 5 2
        if we cut at 4, sub problems are 1 3 and 5 2
        we can't solve them independently as 2 is dependent on 1 3 
        so we must sort the cuts
    */
    sort(cuts.begin(),cuts.end());
    
    vector<vector<int>> dp(c+1,vector<int>(c+1,-1));

    // cout<<minCost_memo(1,c,cuts,dp);
    cout<<minCost_tabu(n,c,cuts);

}

/*
Output:
10 4
1 3 4 7
23
*/