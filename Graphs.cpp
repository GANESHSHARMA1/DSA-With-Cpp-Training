// Graph Usiing Adjacency Matrix

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, 0)); // resizing and initializing each vertices to zero
    }

    void addEdges(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void printAdjMatrix()
    {
        for (auto i = 0; i < vertices; i++)
        {
            for (auto j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph graph(5);
    graph.addEdges(0, 1);
    graph.addEdges(0, 4);
    graph.addEdges(1, 2);
    graph.addEdges(1, 3);
    graph.addEdges(1, 4);
    graph.addEdges(2, 3);
    graph.addEdges(3, 4);
    graph.printAdjMatrix();
    return 0;
}