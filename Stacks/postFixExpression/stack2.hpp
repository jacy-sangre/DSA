#include <iostream>
#include "node2.hpp"

class Stack {   
    private:
    Node* top;

    public:

    Stack(){
        top = nullptr;
    }

    void push(int n){
        Node* newNode = new Node{n, top};
        top = newNode;
    }

    int pop(){
        if(isEmpty()){
            return -1;
        }
        int n = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return n;
    }

    bool isEmpty(){
        return top == nullptr;
    }


};