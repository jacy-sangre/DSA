#include <iostream>
#include "control.hpp"


using namespace std;

int main(){
    Board board;
    Control *control = new Control();
    char op;
    int cut, count;

    do{
        cout << "Op: ";
        cin >> op;
        switch(op){
            case 'p':
                control->print();
                break;
            case 'a':
                cout << "Name: ";
                cin >> board.name;
                cout << "Course: ";
                cin >> board.course;
                cout << "Score: ";
                cin >> board.score;
                
                if(control->add(board)){
                    cout << board.name << " has been added" << endl;
                }else{
                    cout << board.name << " has not been added" << endl;
                }
                break;
            case 'r':
                cout << "Enter cut-off score: ";
                cin >> cut;
                count = control->remove(cut);
                cout << "Number of people removed: " << count << endl;
                break;
            case 'x':
                cout << "Exiting..." << endl;
                break;
            default:
                break;
        }

    }while(op != 'x');
}
