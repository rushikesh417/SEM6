#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Graph {
public:
    unordered_map<int, vector<int>> graph;

    void addEdge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void dfs(int vertex, unordered_map<int, bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    void depthFirstSearch(int startVertex) {
        unordered_map<int, bool> visited;
        for (const auto& entry : graph) {
            visited[entry.first] = false;
        }

        dfs(startVertex, visited);
    }

    void breadthFirstSearch(int startVertex) {
        unordered_map<int, bool> visited;
        for (const auto& entry : graph) {
            visited[entry.first] = false;
        }

        queue<int> q;
        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            cout << currentVertex << " ";

            for (int neighbor : graph[currentVertex]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "Depth-First Search:" << endl;
    g.depthFirstSearch(0);
    cout << "\nBreadth-First Search:" << endl;
    g.breadthFirstSearch(0);

    return 0;
}
