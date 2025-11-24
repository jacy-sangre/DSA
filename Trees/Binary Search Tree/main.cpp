#include "MyBinaryTree.hpp"
#include <unordered_map>
#include <iostream>


using namespace std;

int main(){

    BinaryTree *bt = new MyBinaryTree();
    unordered_map<int, Node*> tree;

    char op;
    int n, res;
    Node* v = nullptr;

    do{
        cout << "Op: ";
        cin >> op;
        switch(op){
            case 'p':
                bt->print();
                break;
            case 'i':
                cin >> n;
                v = bt->insert(n);
                tree[n] = v;
                break;
            case 'r':
                cin >> n;

                if(!bt->getRoot()){
                    cout << "Tree is Empyty" << endl;
                }else{
                    res = bt->remove(bt->search(n));
                    if(res != -1){
                        cout << "Removed " << res << endl;
                    }else{
                        cout << "Element not found" << endl;
                    }
                }

                break;  
            case 'h':
                bt->toHeap();
                cout << "Converting to Heap" << endl;
                break;     
            case 'x':
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }

    }while(op != 'x');

    
}

