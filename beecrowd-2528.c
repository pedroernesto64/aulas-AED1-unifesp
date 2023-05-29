
#include <stdio.h>
#include <stdbool.h>

int minimo(int a, int b) {
    return (a < b) ? a : b;
}

int menor_caminho(int graph[][1001], int vertices, int inicio, int fim, int alvo) {
    int dist[vertices + 1]; 
    int visited[vertices + 1]; 
    int i, j;

    for (i = 1; i <= vertices; i++) {
        dist[i] = 9999999;
        visited[i] = 0;
    }

    dist[inicio] = 0;

    i=1;
    do {
        int u = -1;

        
        j=1;
        while (j <= vertices) {
            if (visited[j]==0 && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
            j++;
        }

        visited[u] = 1;

        j=1;
        for (j = 1; j <= vertices; j++) {
            if (graph[u][j] > 0 && !visited[j]) {
                if (u == alvo || j == alvo)
                    continue;

                dist[j] = minimo(dist[j], dist[u] + graph[u][j]);
            }
        }
        i++;
    } while (i<=vertices);

    return dist[fim];
}

int main() {
    int vertices, cantos, vertA, vertB, inicio, fim, alvo, maisRapido, grafo[1001][1001];

    while (scanf("%d %d", &vertices, &cantos) != EOF) {
        grafo[0][0] = 0;

        for (int i = 0; i < cantos; i++) {
            scanf("%d %d", &vertA, &vertB);
            grafo[vertA][vertB] = 1;
            grafo[vertB][vertA] = 1;
        }

        scanf("%d %d %d", &inicio, &fim, &alvo);

        maisRapido = menor_caminho(grafo, vertices, inicio, fim, alvo);

        printf("%d\n", maisRapido);
    }

    return 0;

}
