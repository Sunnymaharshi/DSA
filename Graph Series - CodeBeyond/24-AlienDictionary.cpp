// https://www.lintcode.com/problem/892/
// lintcode won't check for multiple correct answers,works fine in leetcode
#include<iostream>
#include<vector>
#include<stack>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// topological sort
bool checkCycle(int node, vector<int> &vis,vector<int> &pathvis,vector<int> graph[], stack<int> &st){

    vis[node] = 1;
    pathvis[node] = 1;
    for(auto adj:graph[node]){
        if(!vis[adj]){
            if(checkCycle(adj,vis,pathvis,graph,st)==true)
                return true;
        }
        else if(pathvis[adj]==1)
            return true;
    }
    pathvis[node] = 0;
    st.push(node);             
    return false;               // no cycle

}
string alienOrder(vector<string> &words){

    vector<int> graph[26],present(26,0),vis(26,0), pathvis(26,0); // 26 characters
    int n = words.size();
    for(auto s: words){
        for(auto c:s)
            present[c-'a']=1;
    }
    for(int i=0;i<n-1; i++){
        string s1 = words[i];
        string s2 = words[i+1];
        int m = s1.size();

        for(int j=0;j<m; j++){
            // raja and raj, invalid order
            if(j>=s2.size())
                return "";
            
            if(s1[j]!=s2[j]){
                graph[s1[j]-'a'].push_back(s2[j]-'a');      // edge s1[j]->s2[j]
                break;
            }
        }
    }
    stack<int> st;
    for(int i=0;i<26;i++){
        if(present[i] && !vis[i]){
            if(checkCycle(i,vis,pathvis,graph,st))  // not possible
                return "";
        }
    }
    string s;
    while(!st.empty()){
        s += char(st.top() + 'a');
        st.pop();
    }
    return s;
}
int main() {

    fastio();
    int n;
    string s;
    cin>>n;
    vector<string> words;
    for(int i=0;i<n;i++){
        cin>>s;
        words.push_back(s);
    }
    cout<<alienOrder(words);   
    return 0;
}
/*
Output:
6
wrt
wrf
er
ett
rftt
wertf
*/