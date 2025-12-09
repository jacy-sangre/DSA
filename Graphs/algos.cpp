#include <iostream>
#include <climits>

int main(){
    
}

int graph[10][10];
int size;

void dijkstra(int start){
    int dist[10];
    bool visited[10];

    //Initlialize values to MAX and false
    for(int i = 0; i < size; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[start] = 0; // Set the starting vertex to 0;

    //Repeat n-1 times;
    for(int i = 0; i < size-1; i++){
        int minDist = INT_MAX;
        int u = -1;

        //Pick the vertex that hasn't been visted and get the smallest distance
        for(int j = 0; j < size; j++){
            if(!visited[j] && dist[j] < minDist){
                minDist = dist[j];
                u = j;
            }
        }

        //Set the vertex visisted to true
        visited[u] = true;

        for(int v = 0; v < size; v++){
            if(!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX){
                int newDist = dist[u] + graph[u][v];

                //Update short distance
                if(newDist < dist[v]){
                    dist[v] = newDist;
                }
            }
        }
    }
}

void primJarnik(int start){
    int parent[10];
    int key[10];
    bool visited[10];

    //Initialize
    for(int i = 0; i < size; i++){
        visited[i] = false;
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[start] = 0;

    for(int count = 0; count < size-1; count++){
        int minKey = INT_MAX;
        int u = -1;

        for(int i = 0; i < size; i++){
            if(!visited[i] && key[i] < minKey){
                minKey = key[i];
                u = i;

            }
        }

        visited[u] = true;

        for(int v = 0; v < size; v++){
            if(!visited[v] && graph[u][v] != 0 && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];

            }
        }
    }
}