#include "node.hpp"

class GenTree{
    public:
    virtual void print() = 0;
    virtual Node* addRoot(int val) = 0;
    virtual Node* addChild(Node* parent, int val) = 0;
    virtual int remove(Node* node) = 0;
    virtual int getSize() = 0;
    virtual Node* getRoot() = 0;
    virtual Node* search(int num) = 0;
    virtual int removeAll(int num) = 0;
    virtual int removeByN(int num) = 0;
    virtual Node* getNode(Node* node, int num) = 0;
    virtual void breadthFirstTraversal() = 0;
    virtual void postOrder() = 0;
    virtual void preOrder() = 0;

    



};