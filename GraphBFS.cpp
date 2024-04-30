// BFS Traversal Question Solution)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adjList)
{
    vector<bool> visited(n, false);
    vector<int> traversalOrder;
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        traversalOrder.push_back(frontNode);

        for (int neighbor : adjList[frontNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return traversalOrder;
}

int main()
{
    int n, m;
    cin >> n >> m; // n ->nodes, m->edges

    vector<vector<int>> adjList(n);

    // Read the input and construct AdjList
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    vector<int> result = bfsTraversal(n, adjList);

    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
