#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> dij(vector<vector<pair<int, int>>> &adj, int V, int S)
{
    // dist,node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V);
    for (int i = 0; i < V; i++)
    {
        dist[i] = 1e9;
    }
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto i : adj[node])
        {
            int newnode = i.first;
            int newweight = i.second;
            if (newweight + distance < dist[newnode])
            {
                dist[newnode] = newweight + distance;
                pq.push({dist[newnode], newnode});
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<pair<int, int>>> adj = {
        {{1, 2}, {2, 4}},         // A -> B(2), C(4)
        {{0, 2}, {2, 1}, {3, 7}}, // B -> A(2), C(1), D(7)
        {{0, 4}, {1, 1}, {3, 3}}, // C -> A(4), B(1), D(3)
        {{1, 7}, {2, 3}}          // D -> B(7), C(3)
    };
    int V = 4;
    vector<int> ans = dij(adj, V, 0);
    for (auto i : ans)
    {
        cout << i << "=>";
    }
    return 0;
}