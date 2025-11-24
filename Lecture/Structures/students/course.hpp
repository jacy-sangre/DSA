#include <iostream>
#include "students.hpp"
#include <stdlib.h>
#include <math.h>

using namespace std;

class Course{
    Student** students;
    int size;
    int capacity;
    string courseName;

    void increaseCapacity(){
        if(capacity == size){
            capacity += ceil(capacity * .50);
            students = (Student**) realloc(students, sizeof(Student*) * capacity);
        }
    }

    void decreaseCapacity(){
        if(size <= (capacity * 2) / 3){
            capacity -= floor(capacity * .25);

            if(capacity < 5) capacity = 5;
            students = (Student**) realloc(students, sizeof(Student*) * capacity);
        }
    }

    public:
    Course(string courseName){
        this->courseName = courseName;
        size = 0;
        capacity = 5;
        students = (Student**) malloc(sizeof(Student*) * capacity);
        
    }

    void addStudent(Student *s){
        increaseCapacity();
        students[size++] = s;
    }

    string removeStudent(string name){
        if(size == 0) return "";

        for(int i = 0; i < size; i++){
            if(students[i]->name == name){
                string course = students[i]->course;

                for(int j = i; j < size - 1; j++){
                    students[j] = students[j+1];
                }
                size--;
                decreaseCapacity();
                return course;
            }
        }

        return "";
    }

    void addByYear(Student* s){
        
        increaseCapacity();
        if(size == 0){
            addStudent(s);
            return;
        }

        int pos = -1;
        for(int i = 0; i < size; i++){
            if(s->year > students[i]->year){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            addStudent(s);
            return;
        }

        for(int i = size; i > pos; i--){
            students[i] = students[i-1];
        }
        students[pos] = s;
        size++;

        return;
    }

    void print(){
        cout << "Course: " << courseName << endl;
        cout << "Student size: " << size << "/" << capacity << endl;
        for(int i = 0; i < capacity; i++){
            if(i >= size){
                cout << i+1 << ". (none)" << endl;
            }else{
                cout << i+1 << ". " << students[i]->name << ", " << students[i]->course << " - Year " << students[i]->year << endl;
            }
            
        }
        cout << endl;
    }

};