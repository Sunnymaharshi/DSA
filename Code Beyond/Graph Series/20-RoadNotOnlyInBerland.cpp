// https://codeforces.com/problemset/problem/25/D
#include<iostream>
#include<set>
#include<vector>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// union by size
class DSU {
    private:
        vector<int> parent,size;    
    public:
        DSU(int n){
            for(int i=0;i<=n;i++){
                parent.push_back(i);        // every node parent is itself
                size.push_back(1);          // size of each node is 1
            }
        }
        int findParent(int node){

            if(parent[node]==node)          // ultimate parent
                return node;
            // change parent of current node and all the nodes
            // in path to ultimate parent with ultimate parent
            return parent[node]=findParent(parent[node]);
        }
        void unionOp(int u, int v){

            int pu = findParent(u);
            int pv = findParent(v);
            if(pu==pv)              // already connected
                return;
            // join less size component to large size component
            if(size[pu] < size[pv]){  
                parent[pu] = pv;        // join pu to pv
                size[pv] += size[pu];   // add pu size to pv component
            }
            else {
                parent[pv] = pu;        // join pv to pu
                size[pu] += size[pv];   // add pv size to pu component
            }

        }
};


int main() {

    fastio();
    int n;
    cin>>n;
    DSU dsu(n);
    vector<pair<int,int>> extraRoads;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        if(dsu.findParent(u)==dsu.findParent(v)){    // belong to same component
            extraRoads.push_back({u,v});
        }
        else    
            dsu.unionOp(u,v);               // join cities
    }
    set<int> st;                            // stores all unique ultimate parents
    for(int i=1;i<=n;i++){
        st.insert(dsu.findParent(i));
    }
    int ups = st.size();           // no of components
    int roads = ups-1;             // no of roads to build to connect all components
    cout<<roads<<"\n";
    vector<int> newRoads(st.begin(),st.end());

    for(int i=0;i<roads;i++){
        cout<<extraRoads[i].first<<" "<<extraRoads[i].second<<" ";
        cout<<newRoads[i]<<" "<<newRoads[i+1]<<"\n";
    }
    // solution contains more than 1 correct answer,we can print any one
    return 0;
}
/*
Output:
7
1 2
2 3
3 1
4 5
5 6
6 7
1
3 1 1 4
*/


