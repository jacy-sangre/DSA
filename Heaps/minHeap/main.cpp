#include <iostream>
#include "minHeap.hpp"

int main(){
    minHeapADT *heap = new minHeap();
    int n;
    char op;

    do{
        cout << "Op: ";
        cin >> op;

        switch(op){
            case 'p':
                heap->printGrid();
                break;
            case 'r':
                heap->removeMin();
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