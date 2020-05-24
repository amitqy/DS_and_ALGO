#include<bits/stdc++.h>
using namespace std;
/*
Undirected unweighted generic graph construction and bfs on it
*/

template<typename T>
class Graph{
    public:
    map<T,list<T>> l;
    void addEgde(T x,T y){
      l[x].push_back(y);
      l[y].push_back(x);
    }
    void printGraph(){
        for(auto it: l){
            cout << it.first <<" : ";
            list<T> nbrs = it.second;
        
         for(auto it = nbrs.begin(); it != nbrs.end(); it++){
             cout << *it <<" ";
        }
        cout << endl;
        }
    }
    void bfs(T src){
     map<T,int> visited;
     queue<T> q;
     q.push(src);
     visited[src] = true;
     while (!q.empty())
     {
        T node = q.front();
        cout << node <<" ";
        list<T> nbrs = l[node];
        q.pop();
        for(auto it = nbrs.begin(); it !=  nbrs.end(); it++) {
             if(!visited[*it]){
                 q.push(*it);
                 visited[*it] = true;
             }  
        } 
     }
     }
     
};



int main(int argc, char const *argv[])
{
    Graph<int> g;
    g.addEgde(1,2); 
    g.addEgde(1,3);
    g.addEgde(2,4);
    g.addEgde(1,4);
    g.addEgde(3,4);
    g.bfs(3);
    return 0;
}
