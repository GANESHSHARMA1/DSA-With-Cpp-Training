#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstras(vector<vector<pair<int, int>>> &adjList, int V)
{
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // distance, node
    while (!pq.empty())
    {
        int curr_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (curr_dist > dist[u])
            continue;

        for (auto neighbor : adjList[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int T;
    cin >> T; // Number of Test Cases

    while (T--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<pair<int, int>>> adjList(V);

        for (int i = 0; i < E; i++)
        {
            int u, v, weight;
            cin >> u >> v >> weight;
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }

        vector<int> distance = dijkstras(adjList, V);

        for (int i = 0; i < V; i++)
        {
            cout << distance[i] << " ";
        }
    }
    return 0;
}
