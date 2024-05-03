#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            bool cycleDetected = checkCycleDFS(neighbor, visited, dfsvisited, adjList);
            if (cycleDetected)
            {
                return true;
            }
        }
        else if (dfsvisited[neighbor])
        {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

bool detectCycleDirectedG(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    for (auto &edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (checkCycleDFS(i, visited, dfsvisited, adjList))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    bool hasCycle = detectCycleDirectedG(n, edges);

    if (hasCycle)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}
