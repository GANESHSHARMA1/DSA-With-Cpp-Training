#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &AdjList, vector<bool> &visited, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : AdjList[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, AdjList, visited, component);
        }
    }
}

vector<vector<int>> deapthFirstSearch(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> AdjList(V);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    vector<bool> visited(V, false);
    vector<vector<int>> compnents;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, AdjList, visited, component);
            compnents.push_back(component);
        }
    }
    return compnents;
}

int main()
{
    int V, E;
    cout << "Enter the V and E :" << endl;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter the Edges: " << endl;
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> components = deapthFirstSearch(V, edges);

    cout << "No of Components: " << components.size() << endl;
    for (auto &component : components)
    {
        cout << "Components: ";
        for (int vertex : component)
        {
            cout << " " << vertex;
        }
        cout << endl;
    }
    return 0;
}
