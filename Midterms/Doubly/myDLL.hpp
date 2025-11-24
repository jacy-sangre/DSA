#include <iostream>
#include <math.h>
#include "dNode.hpp"
#include "dll.hpp"

using namespace std;

class myDoubly : public Doubly{
    private:
    int size;
    dNode head, tail;

    dNode* addBetween(int num, dNode* pred, dNode* succ){
        dNode* newNode = new dNode{num, nullptr, nullptr};
        newNode->next = succ;
        newNode->prev = pred;
        pred->next = newNode;
        succ->prev = newNode;
        size++;
        return newNode;
    }

    int removeNode(dNode* n){
        int val = n->val;
        n->prev->next = n->next;
        n->next->prev = n->prev;
        delete n;
        size--;

        return val;
    }


    public:
    myDoubly(){
        head.next = &tail;
        tail.prev = &head;
        size = 0;
    }



    void print(){
        cout << "FROM HEAD: ";
        dNode* temp = head.next;
        while(temp != &tail){
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << endl;
        
        cout << "FROM TAIL: ";
        temp = tail.prev;
        while(temp != &head){
            cout << temp->val << " -> ";
            temp = temp->prev;
        }
        cout << endl;
    }

    int add(int n){
        if(size == 0){
            addTail(n);
            return 1;
        }

        if(size == 1){
            if(n <= head.next->val){
                addHead(n);
                return 1;
            }

            if(n >= tail.prev->val){
                addTail(n);
                return 1;
            }
        }

        if(n < head.next->val){
            addHead(n);
            return 1;
        }

        if(n > tail.prev->val){
            addTail(n);
            return 0;
        }

        
        dNode* curr = head.next;
        while(curr && curr->next != &tail){
            if(curr->val < n && curr->next->val > n){
                break;
            }
            curr = curr->next;
        }

        addBetween(n, curr, curr->next);
        int x = abs(n - head.next->val);
        int y = abs(n - tail.prev->val);
        return (x <= y) ? 1 : 0;


    }
    
    void addHead(int n){
        addBetween(n, &head, head.next);
    }

    void addTail(int n){
        addBetween(n, tail.prev, &tail);
    }

    int removeFirst(){
        return (size == 0) ? -1 : removeNode(head.next);
    }
    int removeLast(){
        return (size == 0) ? -1 : removeNode(tail.prev);
    }
    
    int remove(int n){

        if(size == 0) return -1;

        dNode* curr = head.next;
        int i = 1;
        while(curr != &tail){
            if(curr->val == n){
                if(head.next == curr){
                    removeFirst();
                }else{
                    removeNode(curr);
                }
                return i;
            }else{
                curr = curr->next;;
            }
            i++;
        }

        return -1;
    }

    int removeAll(int n){

        if(size == 0) return -1;

        dNode* curr = head.next;
        int count = 0;
        while(curr != &tail){
            if(curr->val == n){
                dNode* nextNode = curr->next;
                count++;
                if(head.next == curr){
                    removeFirst();
                }else{
                    removeNode(curr);
                }
                curr = nextNode;
            }else{
                curr = curr->next;;
            }  
        }

        return count;
    }

    void addAt(int n, int pos){
        if(pos < 1 || pos > size + 1){
            cout << "Invalid Position" << endl;
            return;
        }

        dNode* curr = head.next;
        for(int i = 1; i < pos; i++){
            curr = curr->next;
        }
        addBetween(n, curr->prev, curr);
    }

    void reverse(){
        if(size <= 1) return;

        dNode* curr = head.next;
        dNode* prev = &tail;
        tail.prev = curr;

        while(curr != &tail){
            dNode* nextNode = curr->next;
            curr->next = prev;
            curr->prev = nextNode;
            prev = curr;
            curr = nextNode;
        }

        head.next = prev;
        prev->prev = &head;       
    }

    int removeAt(int pos){
        if(pos < 1 || pos > size) return -1;

        dNode* curr = head.next;
        for(int i = 1; i < pos; i++){
            curr = curr->next;
        }
        int val = curr->val;
        removeNode(curr);

        return val;
    }

    int get(int pos){
        if(pos < 1 || pos > size) return -1;
        
        dNode* curr;
        if(pos <= (size+1)/2){
            curr = head.next;
            cout << "From the head" << endl;
            for(int i = 1; i < pos; i++){
                curr = curr->next;
            }
            return curr->val;
        }else{
            curr = tail.prev;
            cout << "From the tail" << endl;
            for(int i = size; i > pos; i--){
                curr = curr->prev;
            }
            return curr->val;
        }
    }

    

    

};


