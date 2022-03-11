// Problem Link: https://bit.ly/3pya8CP
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
    we keep letters which are in string B, which is len of longest
    common subsequence, len(A)-lcs_len = no of deletions,
    len(B)-lcs_len = no of insertions.
    total = n+m - 2*lcs_len
*/
int lcs_space_op(string s1,string s2){

    int n=s1.size(),m=s2.size();
    // In tabulation, we're just using previous index values of 1st string
    // cur and prev index values of 1st string
    vector<int> prev(m+1,0),cur(m+1,0);

    // i1<0 base case in memoization
    for(int j=0;j<=m;j++)
        prev[j] = 0;
    
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            // reduce indexes while checking as we've shifted them to store base
            // cases in dp array
            if(s1[i-1]==s2[j-1])
                cur[j] = 1 + prev[j-1];
            else
                cur[j] = max(prev[j],cur[j-1]);
        }

        prev = cur;         // make cur index values of 1st string as previous
    }

    return prev[m];
}

int32_t main() {
    fastio();
    
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();    
    int lcs_len = lcs_space_op(a,b);
    cout<<n+m - 2*lcs_len;    
    return 0;
}
/*
Output:
abcd anc
3
*/