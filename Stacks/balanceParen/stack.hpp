#include <iostream>
#include "node.hpp"

class Stack {   
    private:
    Node* top;

    public:

    Stack(){
        top = nullptr;
    }

    void push(char c){
        Node* newNode = new Node{c, top};
        top = newNode;
    }

    char pop(){
        if(top != nullptr){
            char c = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return c;
        }

        return ' ';
    }

    bool isEmpty(){
        return top == nullptr;
    }

    char peek(){
        if(top == nullptr){
            return ' ';
        }

        return top->data;
         
    }


};