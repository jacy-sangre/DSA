#include <iostream>
#include "maxHeap.hpp"

using namespace std;

int main(){
    int n;
    char op;
    maxHeapADT *heap = new maxHeap();

    do{
        cout << "Op: ";
        cin >> op;

        switch(op){
            case 'p':
                heap->printGrid();
                break;
            case 'r':
                heap->removeMax();
                break;
            case 'a':
                cin >> n;
                heap->add(n);
                break;
            case 'x':
                cout << "Exiting..." << endl;
                break;
            default:        
                break;
        }
    }while(op != 'x');
}