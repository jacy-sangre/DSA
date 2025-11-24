#include <iostream>
#include "arrayList.hpp"

using namespace std;

int main(){ 
    List *list = new arrayList();
    char op;
    int n, pos;

    do{
        cout << "Op: ";
        cin >> op;
        switch(op){
            case 'p':
                list->print();
                break;
            case 'a':
                cin >> n;
                list->add(n);
                break;
            case 'g':
                cin >> pos;
                cout << "Got " << list->get(pos) << endl;
                break;
            case 'r':
                cin >> n;
                list->remove(n);
                break;
            case 'A':
                cin >> n;
                cin >> pos;
                list->addAt(n, pos);
                break;
            case 'R':
                cin >> pos;
                list->removeAt(pos);
                break;
            case 'T':
                cin >> n;
                list->removeAll(n);
                break;
            case 'x':
                cout << "Exiting....";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    }while(op != 'x');
}