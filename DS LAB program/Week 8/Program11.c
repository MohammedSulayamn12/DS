#include<stdio.h>
#define MAX 5
void dfs(int adj[][MAX],int visited[],int start){
    int stack[MAX];
    int top=-1;

    for(int k=0;k<MAX;k++){
        visited[k]=0;
    }

    stack[++top]=start;
    visited[start]=1;

    while(top!=-1){
        start=stack[top--];
        printf("%c-> ",start+65);
        for(int i=0;i<MAX;i++){
            if(adj[start][i] && visited[i]==0){
                stack[++top]=i;
                visited[i]=1;
            }
        }
    }
}
int isConnected(int adj[][MAX], int visited[]) {
    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    dfs(adj, visited, 0);

    for (int i = 0; i < MAX; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }
    return 1;
}
int hasCycleUtil(int adj[][MAX], int visited[], int parent, int current) {
    visited[current] = 1;

    for (int i = 0; i < MAX; i++) {
        if (adj[current][i] == 1) {
            if (!visited[i]) {
                if (hasCycleUtil(adj, visited, current, i)) {
                    return 1;
                }
            }
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}
int hasCycle(int adj[][MAX]) {
    int visited[MAX] = {0};

    for (int i = 0; i < MAX; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(adj, visited, -1, i)) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX];
    int choice;

    while (1) {
        printf("\n1. Enter graph\n2. Perform DFS traversal\n3. Check if graph is connected\n4. Check if graph has a cycle\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the adjacency matrix:\n");
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++) {
                    scanf("%d", &adj[i][j]);
                }
            }
        }
        else if (choice == 2) {

            dfs(adj, visited, 0);
        }
        else if (choice == 3) {
            if (isConnected(adj, visited)) {
                printf("The graph is connected.\n");
            } else {
                printf("The graph is not connected.\n");
            }
        }
        else if (choice == 4) {
            if (hasCycle(adj)) {
                printf("The graph has a cycle.\n");
            } else {
                printf("The graph does not have a cycle.\n");
            }
        }
        else if (choice == 5) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}