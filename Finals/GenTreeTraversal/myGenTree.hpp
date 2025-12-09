#include "genTree.hpp"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <queue>

using namespace std;

class myGenTree : public GenTree {
    int cap;
    int size;
    Node* root;
    
    void printHelper(Node* node, int level) {
        if (node == nullptr) return;

        for (int i = 0; i < level; i++) cout << "     ";

        cout << "+--> " << node->data << endl;

        for (int i = 0; i < node->num_of_children; i++) {
            printHelper(node->children[i], level + 1);
        }
    }

    void deleteSubtree(Node* node){
        for(int i = 0; i < node->num_of_children; i++){
            deleteSubtree(node->children[i]);
        }
        delete[] node->children;
        delete node;
    }

    int countRemoved(Node* node){
        int count = 1;
        for(int i = 0; i < node->num_of_children; i++){
            count += countRemoved(node->children[i]);
        }

        return count;
    }

    //Traversal Helpers
    void pre(Node* n){
        if(!n) return;
        cout << n->data << " ";
        for(int i = 0; i < n->num_of_children; i++){
            pre(n->children[i]);
        }
    }

    void post(Node* n){
        if(!n) return;
        for(int i = 0; i < n->num_of_children; i++){
            post(n->children[i]);
        }
        cout << n->data << " ";
    }

    public:
    myGenTree(){
        cap = 5;
        size = 0;
        root = nullptr;
    }

    void breadthFirstTraversal(){
        queue<Node*> qu;
        qu.push(root);

        while(!qu.empty()){
            Node*  curr = qu.front();
            qu.pop();

            cout << curr->data << " ";

            for(int i = 0; i < curr->num_of_children; i++){
                Node* child = curr->children[i];
                qu.push(child);
            }
        }
    }

    void postOrder(){
        post(root);
    }

    void preOrder(){
        pre(root);
    }

    void print() override {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;;
            return;
        }

        printHelper(root, 0);
    }

    Node* addRoot(int val){
        if(root){
            throw logic_error("Root already exists");
        }
        root = new Node(val);
        size++;
        return root;

    }

    Node* addChild(Node* parent, int val){

        if(!parent){
            throw logic_error("Parent is null");
        }
        if(parent->num_of_children == parent->cap){
            int newCap = parent->cap + ceil(parent->cap * .50);
            Node** newChildren = new Node*[newCap];
            for(int i = 0; i < parent->num_of_children; i++){
                newChildren[i] = parent->children[i];
            }
            delete[] parent->children;
            parent->children = newChildren;
            parent->cap = newCap;
        }
        Node* newNode = new Node(val);
        newNode->parent = parent;
        parent->children[parent->num_of_children] = newNode;
        parent->num_of_children++;
        size++;

        return newNode;
    }

    int removeByN(int n){
        Node* found = getNode(root, n);
        if(found != nullptr){
            return remove(found);
        }

        return 0;
    }

    int removeAll(int num){
        int count = 0;
        Node* target = nullptr;
        while((target = getNode(root, num)) != nullptr){
            remove(target);
            count++;
        }

        return count;
    }

    int remove(Node* node){
        if(!node){
            throw logic_error("Node doesn't exist");
            return 0;
        }
        if(node == root){
            deleteSubtree(node);
            root = nullptr;
            size = 0;
        }

        Node* parent = node->parent;
        if(!parent){
            throw logic_error("Node has no parent");

        }

        int removedCount = countRemoved(node);

        int index = -1;
        for(int i = 0; i < parent->num_of_children; i++){
            if(parent->children[i] == node){
                index = i;
                break;
            }
        }
        deleteSubtree(node);

        if(index != -1){
            for(int i = index; i < parent->num_of_children - 1; i++){
                parent->children[i] = parent->children[i+1];
            }
            parent->num_of_children--;
        }

        size -= removedCount;   
        return 1; 
    }

    int getSize(){
        return size;
    }

    Node* getRoot(){
        return root;
    }

    Node* search(int num){
        return getNode(root, num);
    }

    Node* getNode(Node* node, int num){
        if(!node) throw logic_error("Node is null");
        
        if(node->data == num) return node;

        for(int i = 0; i < node->num_of_children; i++){
            Node* found = getNode(node->children[i], num);
            if(found != nullptr){
                return found;
            }
        }

        return nullptr;

    }

   

};