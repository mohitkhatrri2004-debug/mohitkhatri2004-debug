
#include <bits/stdc++.h>
using namespace std;

#define MAX 20
#define INF 99999

// Prim's Algorithm
void prim(int graph[MAX][MAX], int n) {
    int selected[MAX] = {0};
    int edges = 0, total = 0;
    int i, j, x = -1, y = -1, min;

    selected[0] = 1;

    cout << "\nPrim's MST edges:\n";

    while (edges < n - 1) {
        min = INF;

        for (i = 0; i < n; i++)
            if (selected[i])
                for (j = 0; j < n; j++)
                    if (!selected[j] && graph[i][j] != 0 &&graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }

        if (x == -1) {
            cout << "MST cannot be formed for this graph.\n";
            return;
        }

        cout << x << " - " << y << " : " << min << endl;

        total += min;
        selected[y] = 1;
        edges++;
        x = -1;
    }

    cout << "Total MST cost = " << total << endl;
}

// Find Parent
int findParent(int parent[], int vertex) {
    while (parent[vertex] != vertex)
        vertex = parent[vertex];

    return vertex;
}

// Kruskal's Algorithm
void kruskal(int graph[MAX][MAX], int n) {
    int parent[MAX];
    int edges = 0, total = 0;
    int i, j, u, v, min, x, y;

    for (i = 0; i < n; i++)
        parent[i] = i;

    cout << "\nKruskal's MST edges:\n";

    while (edges < n - 1) {
        min = INF;
        x = -1;
        y = -1;

        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (graph[i][j] != 0 && graph[i][j] < min) {
                    min = graph[i][j];
                    x = i;
                    y = j;
                }

        if (x == -1) {
            cout << "MST cannot be formed for this graph.\n";
            return;
        }

        u = findParent(parent, x);
        v = findParent(parent, y);

        if (u != v) {
            cout << x << " - " << y << " : " << min << endl;

            total += min;
            parent[u] = v;
            edges++;
        }

        graph[x][y] = graph[y][x] = 0;
    }

    cout << "Total MST cost = " << total << endl;
}

// Dijkstra's Algorithm
void dijkstra(int graph[MAX][MAX], int n, int source) {
    int dist[MAX], visited[MAX] = {0};
    int i, count, u, v, min;

    for (i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    for (count = 0; count < n - 1; count++) {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        if (u == -1)
            break;

        visited[u] = 1;

        for (v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "\nDijkstra shortest distances from vertex "
         << source << ":\n";

    for (i = 0; i < n; i++)
        cout << "To " << i << " = " << dist[i] << endl;
}

// Main Function
int main() {
    int graph[MAX][MAX];
    int graphForKruskal[MAX][MAX];
    int n, i, j, source;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter weighted adjacency matrix (0 means no edge):\n";

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            cin >> graph[i][j];
            graphForKruskal[i][j] = graph[i][j];
        }

    prim(graph, n);

    kruskal(graphForKruskal, n);

    cout << "\nEnter source vertex for Dijkstra (0 to " << n - 1 << "): ";
    cin >> source;

    dijkstra(graph, n, source);

    return 0;
}
