#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// DFS Implementation
void dfs(map<char, vector<char>>& graph, char node, set<char>& visited) {
    visited.insert(node);
    cout << node << " "; // Process the node
    for (char neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited);
        }
    }
}

void dfsTraversal(map<char, vector<char>>& graph, char start) {
    set<char> visited;
    dfs(graph, start, visited);
}

// BFS Implementation
void bfs(map<char, vector<char>>& graph, char start) {
    set<char> visited;
    queue<char> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();
        cout << node << " "; // Process the node

        for (char neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

// Main Function
int main() {
    // Define the graph
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };

    // Perform DFS Traversal
    cout << "DFS Traversal: ";
    dfsTraversal(graph, 'A');
    cout << endl;

    // Perform BFS Traversal
    cout << "BFS Traversal: ";
    bfs(graph, 'A');
    cout << endl;

    return 0;
}
