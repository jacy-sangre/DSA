#include "stack.hpp"
#include <stdlib.h>
#include <cmath>

class myStack : public Stack{
    private:
    int size;
    int cap;
    string *arr;

    void increaseCap(){
        if(size == cap){
            cap += ceil(cap * .50);
            arr = (string*)realloc(arr, sizeof(string) * cap);
        }
        
        
    }

    void decreaseCap(){
        if(size < ((cap * 2) / 3.0)){
            cap -= floor(cap * .25);

            if(cap < 5){
                cap = 5;
            }
            arr = (string*)realloc(arr, sizeof(string) * cap);
        }
    }

    public:
    myStack(){
        size = 0;
        cap = 5;
        arr = (string*)malloc(sizeof(string) * cap);
    }

    void push(string s){
        increaseCap();
        arr[size++] = s;
    }

    string pop(){
        if(empty()) return "";
        string val = arr[--size];
        decreaseCap();

        return val;
    }

    string top(){
        if(empty()) return "";
        
        return arr[size-1];
    }

    bool empty(){
        return size <= 0;
    }

    int Size(){
        return size;
    }

    void print(){
        cout << "Stack: ";
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    


};