// https://www.lintcode.com/problem/434/description
// Disjoint Set Union
#include<iostream>
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


void noOfIslands(int n,int m,vector<vector<int>> &ops){
    vector<vector<int>> mat(n,vector<int>(m,0));
    DSU dsu(n*m);
    vector<int> ans;
    int islands=0; 
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    for(auto i:ops){
        int x=i[0],y=i[1];
        if(mat[x][y]==1){              // already an island
            ans.push_back(islands);
            continue;
        }
        
        mat[x][y]=1;                    // mark it is island
        islands++;                      
        int node = x*m + y+1;           // 1 based indexing, convert cell into single number
        for(int ind=0;ind<4;ind++){
            int newx = x + dx[ind];
            int newy = y + dy[ind];
            int newnode = newx*m + newy+1;
            if(newx>=0 && newx<n && newy>=0 & newy<m && mat[newx][newy]==1){  // if it is a island

                if(dsu.findParent(node)!=dsu.findParent(newnode)){      // not connected
                    dsu.unionOp(node,newnode);
                    islands--;              // as we connect both components
                }
            }
        }   
        ans.push_back(islands); 
    }

    for(auto i:ans)
        cout<<i<<" ";

}
int main() {

    fastio();
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> ops;
    for(int i=0;i<k;i++){
        vector<int> t;
        int a,b;
        cin>>a>>b;
        t.push_back(a);
        t.push_back(b);
        ops.push_back(t);        
    }
    noOfIslands(n,m,ops);
    return 0;
}
/*
Output:
4 5 4
1 1
0 1
3 3
3 4
1 1 2 2
*/