#include <iostream>
#include "sNode.hpp"
#include "CLL.hpp"
using namespace std;


int main(){
    CircularLinkedList *cll = new CircularLinkedList();
    char op;
    int n, pos;

    do{
        cout << "Op: ";
        cin >> op;
        switch(op){
            case 'F':
                cin >> n; 
                cll->insertFront(n);
                break;
            case 'E':
                cin >> n; 
                cll->insertEnd(n);
                break;
            case 'r':
                cin >> n; 
                cout << "Removed at position " << cll->remove(n) << endl;
                break;
            case 'i':
                cin >> pos;
                cin >> n; 
                cll->insert(n, pos);
                break;    
            case 'p':
                cll->print();
                break;
            case 'x':
                cout << "Exiting..." << endl;  
                break;
            default:
                cout << "Invalid option" << endl;  
        }
        
    }while(op != 'x');


}
