#include<bits/stdc++.h>
using namespace std;
#define max 20
#define INF 99999

void dijkstra(int graph[max][max],int n,int source){
    int dist[max],visited[max] = {0};
    int edges = 0,total = 0;
    int i,cnt,u,min;

    for(int i=0;i<n;i++){
        dist[i] = INF;
    }

    dist[source] = 0;

    for(cnt = 0; cnt < n-1; cnt++){
        min = INF;
        u = -1;

        for(int i=0;i<n;i++){
            if(!visited[i] && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }
        if(u == -1){
                break;
            }
            visited[u] = 1;

            for(int v = 0;v < n;v++){
                if(!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        cout << "Dijkstra's shortest path " << source << endl;

            for(int i=0;i<n;i++){
                cout << "To " << i << "=" << dist[i] << endl;
            }
    }


int main(){
    int graph[max][max];
    int source;
    int n,i,j;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter weighted adjacency matrix (0 means no edge):\n";

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
     cout << "\nEnter source vertex for Dijkstra (0 to " << n - 1 << "): ";
    cin >> source;

    dijkstra(graph, n, source);
    return 0;
}