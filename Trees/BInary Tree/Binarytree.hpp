#include "biNode.hpp"

class Binarytree{
    public:
    virtual void print() = 0;
    virtual Node* addRoot(int e) = 0;
    virtual Node* addLeft(Node* p, int e) = 0;
    virtual Node* addRight(Node* p, int e) = 0;
    virtual Node* getRoot() = 0;
    virtual int remove(Node* n) = 0;
    virtual int depth(Node* n) = 0;
    virtual int height(Node* n) = 0;
    virtual Node* search(int e) = 0;

};