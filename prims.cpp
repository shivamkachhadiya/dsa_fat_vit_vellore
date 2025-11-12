#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int spanningtree(int V, vector<vector<pair<int, int>>> &adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        // if already visited
        if (vis[node] == 1)
            continue;

        vis[node] = 1;
        sum += wt;

        // all neighbours (adj)
        for (auto nbr : adj[node])
        {
            int adjnode = nbr.first;
            int edw = nbr.second;

            if (!vis[adjnode])
                pq.push({edw, adjnode});
        }
    }
    return sum;
}

int main()
{
    // adjacency list: pair<neighbor, weight>
    vector<vector<pair<int, int>>> adj = {
        {{1, 6}, {2, 3}},                         // A -> B(6), C(3)
        {{0, 6}, {2, 4}, {4, 9}},                 // B -> A(6), C(4), E(9)
        {{0, 3}, {1, 4}, {3, 8}, {4, 7}, {5, 9}}, // C -> A,B,D,E,F
        {{2, 8}, {4, 5}, {5, 6}},                 // D -> C,E,F
        {{1, 9}, {2, 7}, {3, 5}, {5, 4}},         // E -> B,C,D,F
        {{2, 9}, {3, 6}, {4, 4}}                  // F -> C,D,E
    };

    int V = 6;
    int sum = spanningtree(V, adj);
    cout << "Total weight of MST = " << sum << endl;
    return 0;
}
