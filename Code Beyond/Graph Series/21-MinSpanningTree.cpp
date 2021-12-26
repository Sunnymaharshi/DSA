// Kruskal's Minimum Spanning Tree Algorithm
#include<iostream>
#include<algorithm>
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
struct Node{

    int u,v,wt;
    Node(int _u, int _v, int _wt){
        u = _u;
        v = _v;
        wt = _wt;
    }
};
bool comp(Node a, Node b){
    return a.wt<b.wt;              
}

void kruskal(int n, vector<Node> &edges){

    sort(edges.begin(),edges.end(),comp); // ascending order according to edge weights
    int cost=0;
    DSU dsu(n);
    vector<Node> mst;            // contains edges of min spanning tree
    for(auto edge:edges){

        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt; 
        if(dsu.findParent(u)!=dsu.findParent(v)){       // nodes not connected
            dsu.unionOp(u,v);                           // connect the nodes
            mst.push_back(edge);                        
            cost += wt;                               
        }
    }
    for(auto edge:mst)
        cout<<edge.u<<" "<<edge.v<<nl;
    
    cout<<"cost:"<<cost;
}
int main() {

    fastio();
    int n,m;
    cin>>n>>m;
    vector<Node> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(Node(u,v,wt));
    }
    kruskal(n,edges);
    return 0;
}
/*
Output:
5 6
1 2 17
2 3 18
1 4 16
3 4 10
4 5 20
3 5 15
3 4
3 5
1 4
1 2
cost:58
*/