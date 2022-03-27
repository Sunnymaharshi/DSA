// Problem link : https://leetcode.com/problems/edit-distance/
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int editDistance_memo(int i,int j,string &s,string &t,vector<vector<int>> &dp){

	// string s is completed but string t is not completed
	// we insert characters left in target string
	if(i<0)
		return j+1;
	
	// target string is completed, string s is not completed
	// we delete characters left in string s
	if(j<0)
		return i+1;

	if(dp[i][j]!=-1)
		return dp[i][j];
	
	// match remaining characters of both strings
	if(s[i]==t[j])
		return editDistance_memo(i-1,j-1,s,t,dp);

	/* if characters are not matching, perform 3 operations take minimum */
	// insert current character of target string
	// reduce target string, string s stays same
	int insert = 1 + editDistance_memo(i,j-1,s,t,dp);

	// delete current character of string s
	// reduce string s
	int del = 1 + editDistance_memo(i-1,j,s,t,dp);

	// replace current character of string s with target string character
	// reduce both strings
	int replace = 1 + editDistance_memo(i-1,j-1,s,t,dp);        
	
	return dp[i][j] = min(insert,min(del,replace));
}

int editDistance_tabu(string &s,string &t){

	int n=s.size(),m=t.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	// Base cases in memoization
	/* 
		we've negative check i.e i<0 and j<0
		as we can't have negative index in the dp array
		we shift index by 1 to right i.e 0 for -1, 1 for 0
		so on m for m-1 n for n-1.
		we reduce values when checking strings.
	*/
	// i<0 return j+1, j as we've shifted indexes to right
	for(int j=0;j<=m;j++)			
		dp[0][j] = j;

	// j<0 return i+1, i as we've shifted indexes to right
	for(int i=0;i<=n;i++)
		dp[i][0] = i; 
		
	for(int i=1;i<=n;i++){

		for(int j=1;j<=m;j++){
			
			// reduce indexes as we've shifted to right
			if(s[i-1]==t[j-1])
				dp[i][j] = dp[i-1][j-1];
			else{

				int insert = 1 + dp[i][j-1];	
				int del = 1 + dp[i-1][j];	
				int replace = 1 + dp[i-1][j-1];	
				dp[i][j] = min(insert,min(del,replace));
			}
		}
	}
	return dp[n][m];
}
int editDistance_space_op(string &s,string &t){

	int n=s.size(),m=t.size();
	vector<int> prev(m+1,0),cur(m+1,0);

	// i<0 return j+1, j as we've shifted indexes to right
	for(int j=0;j<=m;j++)			
		prev[j] = j;
		
	for(int i=1;i<=n;i++){

		// j<0, return i+1, i as we've shifted indexes to right
		// for any index of string s i.e i, if target is completed
		cur[0] = i;

		for(int j=1;j<=m;j++){
			
			// reduce indexes as we've shifted to right
			if(s[i-1]==t[j-1])
				cur[j] = prev[j-1];
			else{

				int insert = 1 + cur[j-1];	
				int del = 1 + prev[j];	
				int replace = 1 + prev[j-1];	
				cur[j] = min(insert,min(del,replace));
			}
		}

		prev = cur;
	}
	return prev[m];
}

int32_t main() {
	fastio();

	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size();
	// vector<vector<int>> dp(n,vector<int>(m,-1));
	// cout<<editDistance_memo(n-1,m-1,s,t,dp);
	// cout<<editDistance_tabu(s,t);
	cout<<editDistance_space_op(s,t);
	return 0;
}
/*
Output:
horse
ros
3
*/