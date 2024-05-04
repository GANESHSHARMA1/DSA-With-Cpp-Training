// Minimum Spanning Tree :- if a Graph is given with V = 5, and E = 6, Then the MST of this graph will contain V = 5 and E = V - 1 with minimum weight of edges.

#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimMST(int n, int m, vector<pair<pair<int, int>, int>> &edges)
{
    vector<vector<pair<int, int>>> adjList(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    // priority_queue(type of value<w,<u,v>>, container to store values<w,<u,v>>, functor-> sub-function)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Key Array to keep the track of the minimum weight edge connecting each node to MST
    vector<int> key(n + 1, INT_MAX);
    vector<pair<pair<int, int>, int>> mstEdges;

    int startNode = 1;
    key[startNode] = 0;
    pq.push({0, {startNode, startNode}});
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int weight = top.first;
        int u = top.second.first;
        int parent = top.second.second;

        if (key[u] != weight)
            continue;

        if (u != parent)
            mstEdges.push_back({{parent, u}, weight});

        for (auto &neighbor : adjList[u])
        {
            int v = neighbor.first;
            int w = neighbor.second;
            if (w < key[v])
            {
                key[v] = w;
                pq.push({w, {v, u}});
            }
        }
    }
    return mstEdges;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<pair<int, int>, int>> edges(m);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {{u, v}, w};
        }
        vector<pair<pair<int, int>, int>> mstEdges = calculatePrimMST(n, m, edges);
        cout << endl;
        for (auto &edge : mstEdges)
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            cout << u << " " << v << " " << w << endl;
        }
    }
    return 0;
}