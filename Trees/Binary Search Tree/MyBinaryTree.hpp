#include "BinaryTree.hpp"
#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class MyBinaryTree : public BinaryTree{
    int size;
    Node* root;
    int* arr = (int*)malloc(sizeof(int) * 1000);
    int arrSize = 0;
    int j = 0;


    Node* create_node(int e, Node* p){
        Node *newNode = new Node();

        newNode->elem = e;
        newNode->left = newNode->right = nullptr;
        newNode->parent = p;
        size++;

        return newNode;
    }

    void printHelper(Node* n, int level){

        for(int i = 0; i < level; i++){
            cout << "     ";
        }

        string label;
        if(level == 0){
            label = "ROOT: ";
        }else if(n->parent && n->parent->right == n){
            label = "R: ";
        }else{
            label = "L: ";
        }
        cout << "+--> " << label << n->elem << endl;

        if(n->left) printHelper(n->left, level+1);
        if(n->right) printHelper(n->right, level+1);
    }

    Node* left(Node* n){
        return n->left;
    }

    Node* right(Node* n){
        return n->right;
    }

    void inOrderTraversal(Node* n){
        if(!n) return;
        inOrderTraversal(n->left);
        arr[arrSize++] = n->elem;
        inOrderTraversal(n->right);
    }

    void replaceTree(Node* n){
        if(!n) return;
        n->elem = arr[j++];
        replaceTree(n->left);
        replaceTree(n->right);
    }

    public:

    MyBinaryTree(){
        root = nullptr;
        size = 0;
    }

    void print(){
        if(!root){
            throw logic_error("Tree is Empty");
        }

        printHelper(root, 0);
    }
    
    Node* insert(int e){

        if(!root){
            return root = create_node(e, nullptr); 
        }

        Node* curr = root;
        while(true){
            Node*& next = (e < curr->elem) ? curr->left : curr->right;
            if(!next) return next = create_node(e, curr);
            curr = next;
        }
    }

    int remove(Node* n){

        if(!n) return -1;
        int res = n->elem;

        if(n->left && n->right){
            Node* parent = n;
            Node* curr = n->right;

            while(curr->left){
                parent = curr;
                curr = curr->left;
            }

            n->elem = curr->elem;

            if(parent->left == curr) parent->left = curr->right;
            else parent->right = curr->right;
            
            if(curr->right) curr->right->parent = parent;

            delete curr;

        }else{
            Node* parent = n->parent;
            Node* child = (n->left) ? n->left : n->right;

            if(child) child->parent = parent;
            if(!parent) root = child;
            else if(parent->left == n) parent->left = child;
            else parent->right = child;
            
            delete n;

        }

        size--;
        return res;
    }

    Node* search(int e){
        if(!root) return nullptr;
        Node* curr = root;

        while(curr){
            if(curr->elem == e){
                return curr;
            }

            if(e < curr->elem){
                curr = curr->left;
            }else{
                curr = curr->right;
            }  
        }

        return nullptr;
        
    }

    Node* getRoot(){
       return (root) ? root : nullptr; 
    }

    int height(){
        
    }
    int depth(){
        return -1;
    }

    void toHeap(){
        inOrderTraversal(root);
        replaceTree(root);
    }

    





};