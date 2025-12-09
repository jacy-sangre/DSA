#include <iostream>
using namespace std;

class graphsADT{
    public:
    virtual int numVertices() = 0;
    virtual char* vertices() = 0;
    virtual int numEdges() = 0;
    virtual int* edges() = 0;
    virtual int getEdge(char u , char v) = 0;
    virtual char* endVertices(int e) = 0;
    virtual char opposite(char v, int e) = 0;
    virtual int outDegree(char v) = 0;
    virtual int* outgoingEdges(char v) = 0;
    virtual int inDegree(char v) = 0;
    virtual int* incomingEdges(char v) = 0;
    virtual char insertVertex(char v) = 0;
    virtual int insertEdge(char u, char v, int e) = 0;
    virtual void removeVertex(char v) = 0;
    virtual void removeEdge(int e) = 0;
    virtual void print() = 0;
    virtual void DFS(int start) = 0;
    virtual void BFS(int start) = 0;
    

};