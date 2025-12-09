#include <iostream>
#include "AdjacencyList.hpp"

using namespace std;

int main() {
    AdjacencyListADT* graph = new AdjacencyList();
    char op, v, v2;
    int edge;
    char* vertices;
    int* edges;

    do {
        cout << "Op: ";
        cin >> op;

        switch(op) {
            case 'p':
                graph->print();
                break;

            case 'v':
                cin >> v;
                graph->insertVertex(v);
                break;

            case 'V':
                vertices = graph->vertices();
                for(int i = 0; i < graph->numVertices(); i++) {
                    cout << vertices[i] << " ";
                }
                cout << endl;
                break;

            case 'E':
                edges = graph->edges();
                for(int i = 0; i < graph->numEdges(); i++) {
                    cout << edges[i] << " ";
                }
                cout << endl;
                break;

            case 'e':
                cin >> v >> v2 >> edge;
                graph->insertEdge(v, v2, edge);
                break;

            case 'r':
                cin >> edge;
                graph->removeEdge(edge);
                break;

            case 'R':
                cin >> v;
                cout << graph->removeVertex(v);
                break;

            case 'o':
                cin >> v;
                cout << "Out-degree: " << graph->outDegree(v) << endl;
                break;

            case 'i':
                cin >> v;
                cout << "In-degree: " << graph->inDegree(v) << endl;
                break;

            case 'O':
                cin >> v;
                edges = graph->outgoingEdges(v);
                for(int i = 0; i < graph->outDegree(v); i++)
                    cout << edges[i] << " ";
                cout << endl;
                break;

            case 'I':
                cin >> v;
                edges = graph->incomingEdges(v);
                for(int i = 0; i < graph->inDegree(v); i++)
                    cout << edges[i] << " ";
                cout << endl;
                break;

            case 'b':
                cin >> v >> edge;
                cout << "Opposite vertex: " << graph->opposite(v, edge) << endl;
                break;

            case 'g':
                cin >> v >> v2;
                cout << "Edge ID: " << graph->getEdge(v, v2) << endl;
                break;

            case 's':
                cin >> edge;
                vertices = graph->endVertices(edge);
                cout << "End vertices: " << vertices[0] << " " << vertices[1] << endl;
                break;

            case 'x':
                cout << "Exiting." << endl;
                break;

            default:
                cout << "Invalid input." << endl;
                break;
        }

    } while(op != 'x');

    return 0;
}
