#include "AdjacencyListADT.hpp"
#include "vertex.hpp"
#include "Edge.hpp"
#include <iostream>

using namespace std;
class AdjacencyList : public AdjacencyListADT{
    Vertex** s_vertices;
    Edge** s_edges;
    int num_vert;
    int num_edge;

    int getEdgeIndex(int e){
        for(int i = 0; i < num_vert; i++){
            if(s_edges[i]->id == e){
                return i;
            }
        }

        return -1;
    }

    int getIndex(char x){
        for(int i = 0; i < num_vert; i++){
            if(s_vertices[i]->getName() == x){
                return i;
            }
        }

        return -1;
    }

    public:
    AdjacencyList(){
        num_vert = 0;
        num_edge = 0;
        s_vertices = (Vertex**)malloc(10 * sizeof(Vertex*));
        s_edges = (Edge**)malloc(100 * sizeof(Edge*));
    }

    int numVertices() {
        return num_vert;
    }

    char* vertices(){
        char* ret = new char[10];
        int j = 0;
        for(int i = 0; i < num_vert; i++){
            ret[j++] = s_vertices[i]->getName();
        }

        return ret;
    }

    int numEdges(){
        return num_edge;
    }

    int* edges(){
        int* ret = new int[100];
        int j = 0;
        for(int i = 0; i < num_edge; i++){
            ret[j++] = s_edges[i]->id;
        }
        return ret;
    }

    // I recommend to create an EdgeList as Well so the look up these tree methods are faster!
    int getEdge(char u , char v){
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->u == u && s_edges[i]->v == v){
                return s_edges[i]->id;
            }
        }

        return -1;
    }

    char* endVertices(int e){
        char* ret = new char[10];
        ret[0] = '-';
        ret[1] = '-';
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->id == e){
                ret[0] = s_edges[i]->u;
                ret[1] = s_edges[i]->v;
                return ret;
            }
        }

        return ret;
    }

    char opposite(char v, int e) {
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->u == v && s_edges[i]->id == e) return s_edges[i]->v;
            if(s_edges[i]->v == v && s_edges[i]->id == e) return s_edges[i]->u;
        }

        return '-';

    }

    int outDegree(char v){
        return s_vertices[getIndex(v)]->getOutCount();
    }

    int* outgoingEdges(char v){
        return s_vertices[getIndex(v)]->getOutEdges();
    }

    int inDegree(char v){
        return s_vertices[getIndex(v)]->getInCount();
    }
    int* incomingEdges(char v){
        return s_vertices[getIndex(v)]->getInEdges();
    }   

    // Did not care about edge cases hehe!
    bool insertVertex(char v){
        Vertex* ver = new Vertex(v);
        s_vertices[num_vert++] = ver;
        return true;
    }

    bool insertEdge(char u, char v, int e){
        Edge* edge = new Edge(u, v, e);
        s_edges[num_edge++] = edge;
        s_vertices[getIndex(u)]->addOutEdge(e);
        s_vertices[getIndex(v)]->addInEdge(e);
        
        return true;
    }

    int removeVertex(char v){
        int index = getIndex(v);
        int* out_edges = s_vertices[getIndex(v)]->getOutEdges();
        int* in_edges = s_vertices[getIndex(v)]->getInEdges();
        int outCount = outDegree(v);
        int inCount = inDegree(v);

        int totalCount= outCount + inCount;
        int* totalEdges = new int[totalCount];
        int k = 0;

        for(int i = 0; i < outCount; i++) totalEdges[k++] = out_edges[i];
        for(int i = 0; i < inCount; i++) totalEdges[k++] = in_edges[i];
       
        // Removed all the edges of the vertext that is to be from other vertices
        for(int i = 0; i < totalCount; i++){
            int e = totalEdges[i];
            for(int j = 0; j < num_vert; j++){
                s_vertices[j]->removeInEdge(e);
                s_vertices[j]->removeOutEdge(e);
            }
            int edgeIndex = getEdgeIndex(e);
            if(edgeIndex != -1){
                for(int j = edgeIndex; j < num_edge-1; j++){
                    s_edges[j] = s_edges[j+1];
                }
                num_edge--; 
            }
        }

        for(int i = index; i < num_vert-1; i++){
            s_vertices[i] = s_vertices[i+1];
        }
        num_vert--;

        return totalCount;
    }

    bool removeEdge(int e){
        for(int i = 0; i < num_vert; i++){
            s_vertices[i]->removeOutEdge(e);
            s_vertices[i]->removeInEdge(e);
        }

        for(int i = getEdgeIndex(e); i < num_edge-1; i++){
            s_edges[i] = s_edges[i+1];
        }
        num_edge--;
        return true;
        
    }

    void print(){
        for(int i = 0; i < num_vert; i++){
            s_vertices[i]->toString();
        }
    }

    

};