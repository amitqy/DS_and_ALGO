/*
INPUT FORMAT

Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting 
that there exists an edge between vertex ei and 
vertex ej with weight wi (separated by space)

4 4
0 1 3
0 3 5
1 2 1
2 3 8

OUTPUT FORMAT

For each vertex, print its vertex number and its distance 
from source, in a separate line. The vertex number and its 
distance needs to be separated by a single space.

0 0
1 3
2 4
3 5

*/

#include <iostream>
#include <vector>
#include <queue>
#define INF 100000
using namespace std;

int main()
{
    int V, e;
    cin >> V >> e;
    int g[e][e];
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < e; j++)
        {
            g[i][j] = 0;
        }
    }
    int src, dest, weight;
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest >> weight;
        g[src][dest] = weight;
        g[dest][src] = weight;
    }
    cout << endl;

    vector<int> dist(V, INF);
    vector<bool> fin(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int u = pq.top().second;
        fin[u] = true;
        pq.pop();
        for (int v = 0; v < V; v++)
        {
            if (g[u][v] != 0 && fin[v] == false)
            {
                // relaxing
                if (dist[u] + g[u][v] < dist[v])
                {
                    dist[v] = dist[u] + g[u][v];
                    pq.push({dist[v], v}); // priority_queue is made sorting distances so can't do pq.push({v,dist[v]});
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
    return 0;
}