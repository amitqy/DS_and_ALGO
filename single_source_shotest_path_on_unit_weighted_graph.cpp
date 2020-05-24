#include<bits/stdc++.h>
using namespace std;
/*
Undirected unweighted generic graph construction and bfs on it
In BFS the visited array is maintained, so that element is not inserted in the queue again. As we pop the items we use, them(here we just printing them).
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

    void find_shortest_path(T src){
        map<T,int> dist;
        queue<T> q;
        q.push(src);
        for(auto it = l.begin(); it != l.end(); it++ ){
              T node = it->first;
              dist[node] = INT_MAX;
        }
        dist[src] = 0;
        while (!q.empty())
        {
           T data  = q.front();
           q.pop();
          list<T> li =  l[data];
          for(auto it = li.begin(); it != li.end(); it++ ){
              if(dist[*it] == INT_MAX){
                  q.push(*it);
                  dist[*it] = dist[data] + 1;
              }
         }
        } 
        cout << endl;
        for(auto it = l.begin(); it != l.end(); it++ ){
              T node = it->first;
              cout << node <<": " << dist[node];
              cout << endl;
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
    g.find_shortest_path(4);
    return 0;
}
