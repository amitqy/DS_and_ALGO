#include <bits/stdc++.h>

using namespace std;

int *topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int res[], vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/

/*
a----> b ---> c
To do a topological sort we can modify the dfs algorithm. In dfs, first visited node is printed and then dfs is called
on its neighbours. In topolgical sort, first push all the neighbours of the visited node,in a stack(call dfs on them ) then when we return back from 
them,then we push the parent.
Go to 'a',go to 'b', go to 'c', then we don't have any neighbours for c, then push c,...then b, and finally a.
dfs : print,call,print call;
topp : call,go to the deepest,then push it in stack and so on

*/

void topo(vector<int> adj[],bool vis[],int sv,int N,int &k,int ans[]){
    vis[sv] = true;
    for(auto x : adj[sv]){
        if(vis[x] == false){
           vis[x] = true;
           topo(adj,vis,x,N,k,ans);
        }
    }
    ans[k] = sv;
    k++;
    return;
}


int* topoSort(int N, vector<int> adj[]) {
    bool *vis = new bool[N];
    for(int i = 0; i < N; i++){
      vis[i] = false;
    }
    int *ans = new int[N];
    // for(int i = 0; i < N; i++){
    //     ans[i] = 1;
    // }
    int k = 0;
    for(int i = 0; i < N; i++){
        if(vis[i] == false){
         topo(adj,vis,i,N,k,ans);
        }
    }
    int *ans2 = new int[N];
    int idx = 0;
    for(int i = N-1; i >= 0 ; i--){
    ans2[idx] = ans[i];
  //  cout << ans2[idx] << " ";
    idx++;
    }
    return ans2;
}
