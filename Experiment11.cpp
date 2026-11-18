#include <bits/stdc++.h>
using namespace std;

#define MAX 20

// BFS
void bfs(int graph[MAX][MAX], int n, int start) {
    int queue[MAX], visited[MAX] = {0};
    int front = 0, rear = 0;
    int u, v;

    visited[start] = 1;
    queue[rear++] = start;

    cout << "BFS Traversal: ";

    while (front < rear) {
        u = queue[front++];
        cout << u << " ";

        for (v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    cout << endl;
}

// DFS
void dfs(int graph[MAX][MAX], int n, int u, int visited[MAX]) {
    int v;

    visited[u] = 1;
    cout << u << " ";

    for (v = 0; v < n; v++) {
        if (graph[u][v] && !visited[v]) {
            dfs(graph, n, v, visited);
        }
    }
}

// Main Function
int main() {
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int n, i, j, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex (0 to " << n-1 << "): ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(graph, n, start, visited);

    cout << "\nDFS Traversal completed.\n";

    bfs(graph, n, start);

    return 0;
}
