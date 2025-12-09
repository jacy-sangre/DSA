#include <stdlib.h>
#include <iostream>

using namespace std;

class Vertex{
    char name;
    int* out_edges;
    int* in_edges;
    int out_count;
    int in_count;

    public:
    Vertex(char n){
        name = n;
        out_edges = (int*)calloc(10, sizeof(int));
        in_edges = (int*)calloc(10, sizeof(int));
        out_count = 0;
        in_count= 0;
    }

    int getName(){
        return name;
    }

    int getOutCount(){
        return out_count;
    }

    int getInCount(){
        return in_count;
    }

    int* getOutEdges(){
        return out_edges;
    }
    
    int* getInEdges(){
        return in_edges;
    }

    void addOutEdge(int e){
        out_edges[out_count++] = e;
    }
    
    void addInEdge(int e){
        in_edges[in_count++] = e;
    }

    void removeOutEdge(int e){
        int index = -1;
        for(int i = 0; i < out_count; i++){
            if(out_edges[i] == e){
                index = i;
                break;
            }
        }

        if(index == -1) return;
        for(int i = index; i < out_count-1; i++){
            out_edges[i] = out_edges[i+1];
        }
        out_count--;

    }

    void removeInEdge(int e){
        int index = -1;
        for(int i = 0; i < in_count; i++){
            if(in_edges[i] == e){
                index = i;
                break;
            }
        }

        if(index == -1) return;
        for(int i = index; i < in_count-1; i++){
            in_edges[i] = in_edges[i+1];
        }
        in_count--;
    }

    void toString(){
        cout << name << ": ";
        cout << "Outgoing: ";
        for(int i = 0; i < out_count; i++){
            cout << out_edges[i] << " ";
        }
        cout << "| ";
        cout << "Incoming: ";
        for(int i = 0; i < in_count; i++){
            cout << in_edges[i] << " ";
        }
        cout << endl;
    }



};