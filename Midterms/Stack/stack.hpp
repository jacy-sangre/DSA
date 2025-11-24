#include <iostream>

using namespace std;

class Stack{
    public:
    virtual void push(string s) = 0;
    virtual string pop() = 0; 
    virtual string top() = 0;
    virtual bool empty() = 0;
    virtual int Size() = 0;
    virtual void print() = 0;

};