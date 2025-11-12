#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void bfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        for (auto nb : adj[frontnode])
        {
            if (!visited[nb])
            {
                q.push(nb);
                visited[nb] = true;
            }
        }
    }
}

vector<int> bfs_help(vector<vector<int>> &adj)
{

    int vertex = adj.size();
    unordered_map<int, bool> visited;
    vector<int> ans;
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adj, visited, ans, i);
        }
    }
    return ans;
}

int main()
{

    vector<vector<int>> adj = {
        {1, 2},       // A -> B, C
        {0, 2, 3},    // B -> A, C, D
        {0, 1, 3, 4}, // C -> A, B, D, E
        {1, 2, 4, 5}, // D -> B, C, E, F
        {2, 3, 5},    // E -> C, D, F
        {3, 4}        // F -> D, E
    };
    vector<int> final_ans = bfs_help(adj);
    for (auto i : final_ans)
    {
        cout << i << "=>";
    }
}
