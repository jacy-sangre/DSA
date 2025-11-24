#include "Binarytree.hpp"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class MyBinarytree : public Binarytree{
    Node* root;
    int size;

    Node* createNode(Node* parent, int e){
        Node* newNode = new Node();

        newNode->left = newNode->right = nullptr;
        newNode->parent = parent;
        newNode->val = e;
        size++;

        return newNode;
    }

    Node* searchHelp(Node* n, int e){
        if(e == n->val){
            return n;
        }

        if(n->left) searchHelp(n->left, e);
        if(n->right) searchHelp(n->right, e);

    }
    void printHelper(Node* n, int level){
        if(!n) return;

        for(int i = 0; i < level; i++) cout << "     ";

        cout << "+--> " << n->val << endl;

        if(n->left) printHelper(n->left, level + 1);
        if(n->right) printHelper(n->right, level + 1);

    }

    public:
    MyBinarytree(){
        root = nullptr;
        size = 0;
    }

    Node* getRoot(){
        if(!root) return NULL;
        return root;
    }
    
    void print(){
        printHelper(getRoot(), 0);
    }

    Node* addRoot(int e){
        if(root){
            cout << "Tree has a root already" << endl;
            return root;
        }

        return createNode(nullptr, e);
    }


    Node* addLeft(Node* p, int e){
        if(!p) return NULL;
        if(p->left){
            cout << to_string(p->val) << " already has a left child (" << to_string(p->left->val) << ")" << endl;
            return nullptr;
        }

        return p->left = createNode(p, e);
    }

    Node* addRight(Node* p, int e){
        if(!p) return NULL;
        if(p->right){
            cout << to_string(p->val) << " already has a right child (" << to_string(p->right->val) << ")" << endl;
            return nullptr;
        }

        return p->right = createNode(p, e);
    }

    int remove(Node *n){
        if(!n) return -1;
        int ret = n->val;

        if(n->left && n->right){
            cout << "Cannot delete node because it has two children" << endl;
            return -1;
        }

        Node* parent = n->parent;
        Node* child = (n->left) ? n->left : n->right;

        if(child) child->parent = parent;
        if(!parent) root = child;
        else if(parent->left == n) parent->left = child;
        else parent->right = child;
        
        size--;
        delete n;

        return ret;
    }

    Node* search(int e){
       return searchHelp(root, e);
    }

    int depth(Node* n){
        int d = 0;
        while(n && n != root){
            n = n->parent;
            d++;
        }

        return d;
    }

    int height(Node* n){
        return 1 + max(height(n->left), height(n->right));
    }



    
};