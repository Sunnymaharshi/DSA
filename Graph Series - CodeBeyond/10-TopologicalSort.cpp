/* toposort is not possible for undirected graph and cyclic graph
possible for directed acyclic graph(DAG) only
linear ordering of vertices
u comes before v if there's directed edge u->v */
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
void topoSort(int node,stack<int> &st, vector<int> &vis, vector<int> graph[]){

    vis[node]=1;
    for(auto i:graph[node]){
        if(vis[i]==0){
            topoSort(i,st,vis,graph);
        }
    }
    st.push(node); // if no adjacent nodes or after calling it's adjacent nodes
    // when poping from stact if u->v , u comes first and then v, as u added to stack after it's adjacent nodes
}

int main() {

    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1],vis(n+1,0);
    stack<int> st;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++){      // to traverse all the components
        if(vis[i]==0){
            topoSort(i,st,vis,graph);
        }
    }

    cout<<"Topological Sort:";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
/*
Output:
5 5
5 1
2 1
3 1
4 5
4 3
Topological Sort:4 5 3 2 1 
*/