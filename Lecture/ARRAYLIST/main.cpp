#include <iostream>
#include "arraylist.hpp"

using namespace std;

int main(){
    
    List* list = new arrayList();
    char op;
    int n, pos;

    do{
        cout << "Op: ";
        cin >> op;

        switch(op){
            case 'a':
                cin >> n;
                list->add(n);
                break;
            case 'p':
                list->print();
                break;
            case 'r':
                cin >> n;
                list->remove(n);
                break;
            case 'f':
                cin >> n;
                list->addFirst(n);
                break;
            case 'l':
                cin >> n;
                list->addLast(n);
                break;
            case 'F':
                list->flip();
                cout << "List flipped" << endl;
                break;
            case 'A':
                cin >> n;
                cin >> pos;
                list->addAt(n, pos);
                break;
            case 'R':
                cin >> n;
                cout << "Number of items removed: " << list->removeAll(n) << endl;
                break;

            case 'x':
                cout << "Exiting..." << endl;
                break;
        }

    }while(op != 'x');
}