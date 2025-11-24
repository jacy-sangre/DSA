#include <iostream>
#include "course.hpp"

using namespace std;

int main(){
     
    Course* s = new Course("CSIT221");
    char op;
    string name, course;
    int year;
    Student* st;

    do{
        cout << "Op: ";
        cin >> op;
        switch(op){
            case 'a':
                st = new Student();
                cout << "Name: ";
                cin >> st->name;
                cout << "Course and Year: ";
                cin >> st->course;
                cin >> st->year;
                s->addStudent(st);
                break;
            case 'r':
                cout << "Name: ";
                cin >> name;
                course = s->removeStudent(name);
                if(course == ""){
                    cout << "Student not found!" << endl;
                }else{
                    cout << "Removed from " << course << endl;
                }
                break;
            case 'y':
                st = new Student();
                cout << "Name: ";
                cin >> st->name;
                cout << "Course: ";
                cin >> st->course;
                cout << "Year: ";
                cin >> st->year;
                s->addByYear(st);
                break;
            case 'p':
                s->print();
                break;
            case 'x':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid operation!" << endl;
                break;
        }   
       

    }while(op != 'x');
}