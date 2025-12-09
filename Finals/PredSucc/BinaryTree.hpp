#include "node.hpp"

class BinaryTree{
    public:
    virtual void print() = 0;
    virtual Node* insert(int e) = 0;
    virtual int remove(Node* e) = 0;
    virtual Node* search(int e) = 0;
    virtual Node* getRoot() = 0;
    virtual int predeccesor(int n) = 0;
    virtual int successor(int n) = 0;

};