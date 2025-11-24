#include <iostream>
#include "myDLL.hpp"

int main() {

    Doubly *d = new myDoubly();
    char op;
    int n;

    do{
        cout << "Op: ";
        cin >> op;

        switch(op){
            case 'p':
                d->print();
                break;
            case 'a':
                cin >> n;
                if(d->add(n) == 1){
                    cout << "From Head" << endl;
                }else{
                    cout << "From Tail" << endl;
                }
                break;
            case 'x':
                cout << "Exiting..." << endl;    
                break;
            default:
                cout << "Invalid" << endl;    
        }


    }while(op != 'x');
    
}