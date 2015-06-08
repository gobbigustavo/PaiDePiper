#include <stdio.h>
#include <limits.h>
#define N 6

int dijsktra(int graph[][N], int source, int target) {
    int distance[N], prev[N], selected[N] = {0};
    int i, m, min, start, d, j;
    char path[N], path_aux[N];

    for(i = 1; i < N; i++) {
        distance[i] = LONG_MAX;
        prev[i] = -1;
    }

    start = source;
    selected[start] = 1;
    distance[start] = 0;

    while(selected[target] == 0) {
        min = LONG_MAX;
        m = 0;

        for(i = 1; i < N; i++) {
            d = distance[start] + graph[start][i];
            if(d < distance[i] && selected[i] == 0) {
                distance[i] = d;
                prev[i] = start;
            }
            if(min > distance[i] && selected[i] == 0) {
                min = distance[i];
                m = i;
            }
        }

        start = m;
        selected[start] = 1;
    }

    start = target;
    j = 0;

    while(start != -1) {
        path[j++] = start + 64;
        start = prev[start];
    }

    path[j] = '\0';
    #ifdef _WIN32
        strrev(path);
        printf("\nPath: %s", path);
    #endif
    #ifdef __gnu_linux__
        int tamanho = strlen(path) - 1;

        for(i = 0; path[i] != '\0'; i++) {
            path_aux[tamanho] = path[i];
            tamanho--;
        }
        path_aux[i] = '\0';
        printf("\nPath: %s", path_aux);
    #endif
    return distance[target];
}

int main() {
    int graph[N][N], i, j;
    int weight, best_way;
    int source, target, x, y;
    printf("Dijksrtra's Algorithm\n\n");

    for(i = 1; i < N; i++) {
        for(j = 1; j < N; j++) {
            graph[i][j] = LONG_MAX;
        }
    }

    for(x = 1; x < N; x++) {
        for(y = x + 1; y < N; y++) {
            printf("Enter the weight of the path between node %c and %c: ",x + 64, y + 64);
            scanf("%d",&weight);
            graph[x][y] = graph[y][x] = weight;
        }
        printf("\n");
    }

    printf("\nEnter The Source: ");
    scanf("%d", &source);
    printf("\nEnter The target: ");
    scanf("%d", &target);
    best_way = dijsktra(graph, source, target);
    printf("\nShortest Path: %d", best_way);

    return 0;
}
