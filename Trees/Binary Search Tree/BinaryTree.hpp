#include "node.hpp"

class BinaryTree{
    public:
    virtual void print() = 0;
    virtual Node* insert(int e) = 0;
    virtual int remove(Node* e) = 0;
    virtual Node* search(int e) = 0;
    virtual Node* getRoot() = 0;
    virtual int height() = 0;
    virtual int depth() = 0;
    virtual void toHeap() = 0;

};