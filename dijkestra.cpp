#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkestra(int V, vector<vector<pair<int, int>>> &adj, int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V);
    for (int i = 0; i < V; i++)
        dist[i] = 1e9;

    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int edgeWeight = it.second;
            int adjNode = it.first;

            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    // adjacency list: pair<neighbor, weight>
    vector<vector<pair<int, int>>> adj = {
        {{1, 2}, {2, 4}},         // A -> B(2), C(4)
        {{0, 2}, {2, 1}, {3, 7}}, // B -> A(2), C(1), D(7)
        {{0, 4}, {1, 1}, {3, 3}}, // C -> A(4), B(1), D(3)
        {{1, 7}, {2, 3}}          // D -> B(7), C(3)
    };

    int V = 4;
    vector<int> ans = dijkestra(V, adj, 0);
    for (auto x : ans)
    {
        cout << x << "=>";
    }
    return 0;
}
