#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;
    bool* visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

// Graph initialization
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

// Adding Edges
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_front(dest);
}

// Algorithm
void Graph::DFS(int vertex) {
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
    cout << "Enter count of vertex between 3 and 10"<<endl;
    int countOfgraphs;
    cin >> countOfgraphs;
    if ((countOfgraphs > 10) || (countOfgraphs < 3))
    {
        cout << "Enter count between 3 and 10"<<endl;
        cin >> countOfgraphs;
    }
    Graph g(countOfgraphs);
    for (int i=0; i < countOfgraphs; i++)
    {
        int first, second;
        cout << "Enter first coordinate edge" << endl;
        cin >> first;
        cout << "Enter second coordinate edge" << endl;
        cin >> second;
        g.addEdge(first, second);
    }
    cout << "Which vertex to use for depth - first search?" << endl << "Enter count between 1 and " << countOfgraphs << endl;
    int number;
    cin >> number;
    g.DFS(number);

    return 0;
}