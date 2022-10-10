// Problem Link: https://bit.ly/3KHsl9J
#include<iostream>
#include<vector>
#include<algorithm>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// like lis, but diff should be 1 character -> a ab adb

bool comp(string &s1,string &s2){
    return s1.size() < s2.size();
}
bool isPossible(string &cur,string &prev){

    // they can only differ by 1 char
    if(cur.size() != prev.size()+1) return false;

    int first=0,second=0;

    while(first < cur.size()){

        if(second<prev.size() && cur[first] == prev[second]){
            first++;
            second++;
        }
        else
            first++;
    }

    // they both differ by 1 char
    if(first == cur.size() && second == prev.size())
        return true;
    
    return false;
}
int lsc(vector<string> &arr,int n){


    // sort strings as we want subset not subsequence
    sort(arr.begin(),arr.end(),comp);

    int lsc_len = 0;

    // min lsc for every element is 1
    vector<int> dp(n,1);
            

    // check all prev elements which can be part of lsc with current element
    for(int cur=0;cur<n;cur++){      

        for(int prev=0;prev<cur;prev++){

            // can be included
            if(isPossible(arr[cur],arr[prev]) && 1+dp[prev]>dp[cur]){

                dp[cur] = 1+dp[prev];
            }
        }
        // dp[cur] specifies length of longest lsc ending at current element
        if(dp[cur]>lsc_len){

            lsc_len = dp[cur];            
        }
    }
    return lsc_len;
}
int main() {
    fastio();

    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<lsc(arr,n); 
}

/*
Output:
4
x xx y xyx
3
*/