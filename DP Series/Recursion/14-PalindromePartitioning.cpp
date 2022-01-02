// https://leetcode.com/problems/palindrome-partitioning/
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool isPalindrome(string s,int start, int end){

    while(start<=end){
        if(s[start++]!=s[end--])
            return false;        
    }
    return true;
}
void partition(int ind,string s,vector<string> &parts,vector<vector<string>> &ans){

    if(ind==s.size()){
        ans.emplace_back(parts);
        return;
    }
    for(int i=ind;i<s.size();i++){

        if(isPalindrome(s,ind,i)){      // check if ind to i is palindrome

            // add partition [ind to i] to parts
            parts.push_back(s.substr(ind,i-ind+1));
            partition(i+1,s,parts,ans);  // do partitions from i+1 index
            parts.pop_back();            // remove the partition
        }
    }

}
int32_t main() {
    fastio();
    string s;
    cin>>s;
    vector<vector<string>> ans;
    vector<string> parts;
    partition(0,s,parts,ans);
    for(auto partition:ans){
        for(auto part:partition){
            cout<<part<<sp;
        }
        cout<<nl;
    }
    return 0;
}
/*
Output:
aab
a a b 
aa b
*/