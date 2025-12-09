#include "edgeNode.hpp"
#include "graphsADT.hpp"

class EdgeList : public graphsADT{
    char* verticesList;
    Edge* edgeList;
    int numOfVertices;
    int numOfEdges;

    int getIndex(char v){
        for(int i = 0; i < numOfVertices; i++){
            if(v == verticesList[i]){
                return i;
            }
        }
        return -1;
    }

    public:
    EdgeList(){
        verticesList = new char[10];
        edgeList = new Edge[90];
        numOfEdges = 0;
        numOfVertices = 0;
    }

    int numVertices(){
        
        return numOfVertices;
    }
    char* vertices(){
        if(numOfVertices == 0) return NULL;
        return verticesList;
    }
    int numEdges(){
        return numOfEdges;
    }

    int* edges(){
        if(numOfEdges == 0) return NULL;
        int* out = new int[100];
        for(int i = 0; i < numOfEdges; i++){
            out[i] = edgeList[i].e;
        }
        return out;
    }

    int getEdge(char u , char v){
        for(int i = 0; i < numOfEdges; i++){
            if(edgeList[i].u == u && edgeList[i].v == v){
                return edgeList[i].e;
            }
        }

        return -1;
    }

    char* endVertices(int e){
        char* out = new char[2];
        for(int i = 0; i < numOfEdges; i++){
            if(edgeList[i].e == e){
                out[0] = edgeList[i].u;
                out[1] = edgeList[i].v;
                return out;
            }
        }

        return NULL;
    }

    char opposite(char v, int e){
        for(int i = 0; i < numOfEdges; i++){
            if(edgeList[i].u == v && edgeList[i].e == e) return edgeList[i].v;
            if(edgeList[i].v == v && edgeList[i].e == e) return edgeList[i].u;
        }

        throw logic_error("NOTHING");
    }

    int outDegree(char v){
        int count = 0;
        for(int i = 0; i < numOfEdges; i++){
            if(edgeList[i].u == v){
                count++;
            }
        }
        return count;

    }
    int* outgoingEdges(char v){
        int* out = new int[100];
        int j = 0;

        for(int i = 0; i < numOfEdges; i++){
            if(edgeList[i].u == v){
                out[j++] = edgeList[i].e;
            }
        }

        return (j != 0) ? out : NULL;
    }

    int inDegree(char v){
        int count = 0;
        for(int i = 0; i < numOfEdges; i++){
            if(edgeList[i].v == v){
                count++;
            }
        }
        return count;
    }
    int* incomingEdges(char v){
        int* out = new int[100];
        int j = 0;

        for(int i = 0; i < numOfEdges; i++){
            if(edgeList[i].v == v){
                out[j++] = edgeList[i].e;
            }
        }

        return (j != 0) ? out : NULL;
    }

    char insertVertex(char v){
        for(int i = 0; i < numOfVertices; i++){
            if(verticesList[i] == v) return '\0';
        }
        verticesList[numOfVertices++] = v;
        return v;
    }

    int insertEdge(char u, char v, int e){
        for(int i = 0; i < numOfEdges; i++){
            if(edgeList[i].e == e) return -1;
        }

        edgeList[numOfEdges++] = {u, v, e};
        return e;
    }

    void removeVertex(char v){
        int index;
        if((index = getIndex(v)) == -1) return;

        for(int i = index; i < numOfVertices-1; i++){
            verticesList[i] = verticesList[i+1];
        }
        numOfVertices--;

        for(int i = 0; i < numOfEdges; i++){
            if(edgeList[i].u == v || edgeList[i].v == v){
                for(int j = i; j < numOfEdges-1; j++){
                    edgeList[j] = edgeList[j+1];
                }
                numOfEdges--;
                i--;
            }
        }
    }

    void removeEdge(int e){
        for(int i = 0; i < numOfEdges; i++){
            if(edgeList[i].e == e){
                for(int j = i; j < numOfEdges-1; j++){
                    edgeList[j] = edgeList[j+1];
                }
                numOfEdges--;
                break;
            }
        }
    }
    void print(){

    }

    


};