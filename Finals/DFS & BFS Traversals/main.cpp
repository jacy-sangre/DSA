#include <iostream>
#include "dfs_bfs_tarversals.hpp"

using namespace std;

int main(){
    graphsADT* graph = new dfs_bfs_adjacencyMatrix();
    char op, v, v2;
    int edge, deg, start;
    char* vertices;
    int* edges;

    do{
        cout << "Op: ";
        cin >> op;
        switch(op){
            case 'p':
                graph->print();
                break;
            case 'v':
                cin >> v;
                graph->insertVertex(v);
                break;
            case 'V':
                vertices = graph->vertices();
                for(int i = 0; i < graph->numVertices(); i++){
                    cout << vertices[i] << " ";
                }
                cout << endl;
                break; 
            case 'E':
                edges = graph->edges();
                for(int i = 0; i < graph->numEdges(); i++){
                    cout << edges[i] << " ";
                }
                cout << endl;
                break;    
            case 'e':
                cin >> v;
                cin >> v2;
                cin >> edge;
                graph->insertEdge(v, v2, edge);
                break;
            case 'r':
                cin >> edge;
                graph->removeEdge(edge);
                break;
            case 'R':
                cin >> v;
                graph->removeVertex(v);
                break;  
            case 'o':
                cin >> v;
                cout << graph->outDegree(v) << endl;
                break;     
            case 'i':
                cin >> v;
                cout << graph->inDegree(v) << endl;
                break;
            case 'O':
                cin >> v;
                edges = graph->outgoingEdges(v);
                for(int i = 0; i < graph->outDegree(v); i++){
                    cout << edges[i] << " ";
                }
                cout << endl;
                break;     
            case 'I':
                cin >> v;
                edges = graph->incomingEdges(v);
                for(int i = 0; i < graph->inDegree(v); i++){
                    cout << edges[i] << " ";
                }
                cout << endl;
                break; 
            case 'b':
                cin >> v;
                cin >> edge;
                cout << graph->opposite(v, edge) << endl;
                break;   
            case 'g':
                cin >> v;
                cin >> v2;
                cout << graph->getEdge(v, v2) << endl;
                break; 
            case 's':
                cin >> edge;
                vertices = graph->endVertices(edge);
                for(int i = 0; i < 2; i++){
                    cout << vertices[i] << " ";
                }
                cout << endl; 
                break;
            case 'D':
                cin >> start;
                graph->DFS(start);
                break;  
            case 'B':
                cin >> start;
                graph->BFS(start);
                break;                                   
            case 'x':
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                break;                
        }

    }while(op != 'x');
}