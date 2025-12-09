#include "graphsADT.hpp"
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

class ShortestPath_adjacencyMatrix : public graphsADT{
    int numOfVertices;
    int numOfEdges;
    int** graphMatrix;
    int* edgesList;
    char* verticesList;

    //Helper Methods
    int getIndex(char v){
        for(int i = 0; i < numOfVertices; i++){
            if(verticesList[i] == v){
                return i;
            }
        }
        return -1;
    }

    void removeHelper(int x, int y){
        int e = graphMatrix[x][y];
        graphMatrix[x][y] = 0;

        int index = -1;
        for(int i = 0; i < numOfEdges; i++){
            if(edgesList[i] == e){
                index = i;
                break;
            }
        }

        //Update EdgeList
        if(index == -1) return;
        for(int i = index; i < numOfEdges-1; i++){
            edgesList[i] = edgesList[i+1];
        }
        numOfEdges--;
    }

    public:
    ShortestPath_adjacencyMatrix(){
        numOfVertices = 0;
        numOfEdges = 0;

        graphMatrix = (int**)calloc(10, sizeof(int*));
        for(int i = 0; i < 10; i++){
            graphMatrix[i] = (int*)calloc(10, sizeof(int));
        }

        edgesList = new int[100];
        verticesList = new char[10];
    } 

    int shortestPath(char u, char v){
        int start = getIndex(u);
        int target = getIndex(v);

        bool visited[10];
        int dist[10];

        for(int i = 0; i < numOfVertices; i++){
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[start] = 0;

        for(int i = 0; i < numOfVertices-1; i++){
            int minDist = INT_MAX;
            int u = -1;

            for(int j = 0; j < numOfVertices; j++){
                if(!visited[j] && dist[j] < minDist){
                    minDist = dist[j];
                    u = j;
                }
            }

            visited[u] = true;

            for(int v = 0; v < numOfVertices; v++){
                if(graphMatrix[u][v] != 0 && !visited[v] && dist[u] != INT_MAX){
                    int newDist = graphMatrix[u][v] + dist[u];

                    if(newDist < dist[v]){
                        dist[v] = newDist;
                    }
                }
            }
        }

        return (dist[target] != INT_MAX) ? dist[target] : -1;

    }

    

    int numVertices(){
        return numOfVertices;
    }
    
    char* vertices(){
        return verticesList;
    }

    int numEdges(){
        return numOfEdges;
    }
    
    int* edges(){
        return edgesList;
    }

    int getEdge(char u , char v){
        int x, y;
        if((x = getIndex(u)) == -1 || (y = getIndex(v)) == -1 ) return -1;
        if(graphMatrix[x][y] == 0) return -1;
        
        return graphMatrix[x][y];
    }

    char* endVertices(int e){
        for(int i = 0; i < numOfVertices; i++){
            for(int j = 0; j < numOfVertices; j++){
                if(graphMatrix[i][j] == e){
                    char* res = new char[2];
                    res[0] = verticesList[i];
                    res[1] = verticesList[j];
                    return res;

                }
            }
        }

        return NULL;
    }

    char opposite(char v, int e){
        int index;
        if((index = getIndex(v)) == -1) return '\0';
        
        for(int i = 0; i < numOfVertices ; i++){
            if(graphMatrix[index][i] == e) return verticesList[i]; 
            if(graphMatrix[i][index] == e) return verticesList[i];
        }
        
        throw logic_error("No opposite");
    }

    int outDegree(char v){
        int index;
        if((index = getIndex(v)) == -1) return -1;

        int count = 0;
        for(int i = 0; i < numOfVertices ; i++){
            if(graphMatrix[index][i] != 0) count++;  
        }

        return count;
    }

    int* outgoingEdges(char v){
        int index;
        if((index = getIndex(v)) == -1) return NULL;

        int* res = new int[numOfVertices];
        int j = 0;

        for(int i = 0; i < numOfVertices ; i++){
            if(graphMatrix[index][i] != 0) res[j++] = graphMatrix[index][i];
        }

        return res;
    }

    int inDegree(char v){
        int index;
        if((index = getIndex(v)) == -1) return -1;

        int count = 0;
        for(int i = 0; i < numOfVertices ; i++){
            if(graphMatrix[i][index] != 0) count++;  
        }

        return count;
    }

    int* incomingEdges(char v){
        int index;
        if((index = getIndex(v)) == -1) return NULL;

        int* res = new int[numOfVertices];
        int k = 0;

        for(int i = 0; i < numOfVertices ; i++){
            if(graphMatrix[i][index] != 0) res[k++] = graphMatrix[i][index];
        }

        return res;
    }

    char insertVertex(char v){
        for(int i = 0; i < numOfVertices; i++){
            if(v == verticesList[i]) return '\0';
        }
        return verticesList[numOfVertices++] = v;
    }

    int insertEdge(char u, char v, int e){
        for(int i = 0; i < numOfEdges; i++){
            if(e == edgesList[i]) return -1;
        }

        int x, y;
        if((x = getIndex(u)) == -1 || (y = getIndex(v)) == -1 ) return -1;
        if(x == y) return -1;
        if(graphMatrix[x][y] != 0) return -1;

        edgesList[numOfEdges++] = e;
        return graphMatrix[x][y] = e;
    };

    void removeVertex(char v){
        int index;
        if((index = getIndex(v)) == -1) return;

        //Clear row to be deleted
        for(int i = 0; i < numOfVertices; i++){
            if(graphMatrix[index][i] != 0) removeHelper(index, i);
            if(graphMatrix[i][index] != 0) removeHelper(i, index);  
        }
        
        //Shift Up
        for(int i = index; i < numOfVertices-1; i++){
            for(int j = 0; j < numOfVertices; j++){
                graphMatrix[i][j] = graphMatrix[i+1][j];
            }
        }

        //Shift Left
        for(int j = index; j < numOfVertices-1; j++){
            for(int i = 0; i < numOfVertices; i++){
                graphMatrix[i][j] = graphMatrix[i][j+1];
            }
        }

        //Clear the last row and column to zero
        for(int i = 0; i < numOfVertices; i++){
            graphMatrix[numOfVertices-1][i] = 0;
             graphMatrix[i][numOfVertices-1] = 0;
        }

        //Update verticesList
        for(int i = index; i < numOfVertices-1; i++){
            verticesList[i] = verticesList[i+1];
        }
        numOfVertices--;
        return;
    }

    void removeEdge(int e){
        char* ver = endVertices(e);
        if(ver == NULL) return;
        removeHelper(getIndex(ver[0]), getIndex(ver[1]));        
         
    }

    void print(){
        cout << " \t";
        for(int i = 0; i < numOfVertices; i++){
            cout << verticesList[i] << "\t";
        }
        cout << endl;
        
        for(int i = 0; i < numOfVertices; i++){
            cout << verticesList[i] << "\t";
            for(int j = 0; j < numOfVertices; j++){
                if(graphMatrix[i][j] == 0) cout << " \t";
                else cout << graphMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    

    
    
};