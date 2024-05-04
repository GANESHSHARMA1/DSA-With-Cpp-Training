// Disjoint set
// 1. Find Parent
// 2. Union (based on Rank and Size)  --> Rank of Parent node will be 0
//      If a node gets child then the Rank will be incremented
//      If the Ranks are same we can merge them
// 3. Path Compression

//---------------------------------------------------------------------

// Kruskal Algorithm :-
// 1. Note All Edges(weight, u, v)
// 2. Sort Edges according to their weight
// 3. If parents (Ultimate Parent) of u and v are same Then ignore them else merge them

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n);

        // Polpulate parent[] with their node parents
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool union_set(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v)
        {
            if (rank[root_u] > rank[root_v])
                parent[root_v] = root_u;
            else if (rank[root_u] < rank[root_v])
                parent[root_u] = root_v;
            else
            {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
            return true;
        }
        return false;
    }
};

int mstKruskal(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    int mst_Weight = 0;
    for (auto edge : edges)
    {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (uf.union_set(u, v))
        {
            mst_Weight += w;
        }
    }
    return mst_Weight;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    int mspWeight = mstKruskal(edges, V);
    cout << mspWeight << endl;
    return 0;
}