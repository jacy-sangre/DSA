#include <iostream>

using namespace std;

class CircularLinkedList{
    private:
    sNode* tail;
    int size;

    public:
    CircularLinkedList(){
        tail = nullptr;
        size = 0;
    }

    void insertFront(int val){
        sNode* newNode = new sNode(val); 
        if(!tail){
            tail = newNode;
            tail->next = newNode;
        }else{
            newNode->next = tail->next;
            tail->next = newNode;
        }
        size++;
    }

    void insertEnd(int val){
        sNode* newNode = new sNode(val); 
        if(!tail){
            tail = newNode;
            tail->next = newNode;
        }else{
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insert(int pos, int val){

        if(!tail){
            insertEnd(val);
            return;
        }

        sNode* newNode = new sNode(val);

        if(pos == 1){
            insertFront(val);
            return;
        }else if(pos == size+1){
            insertEnd(val);
            return;
        }else{
            sNode* curr = tail->next;
            for(int i = 1; i < pos-1; i++){
                curr = curr->next;
            }

            if(curr){
                newNode->next = curr->next;
                curr->next = newNode;
                size++;
            }
        }
    
    }

    int remove(int n){

        if(!tail) return -1;

        int pos = 0;
        sNode* curr = tail->next;
        sNode* prev = tail;
        
        do{
            pos++;
            if(curr->data == n){
                if(curr == tail && curr == tail->next){
                    delete curr;
                    tail = nullptr;
                }else{
                    prev->next = curr->next;
                    if(tail == curr) tail = prev;
                    delete curr;
                }
                size--;
                return pos;
            }
            prev = curr;
            curr = curr->next;
        }while(curr != tail->next);

        return -1;
        
    }

    void print(){
        if(!tail){
            cout << "List is Empty" << endl;
            return;
        } 

        sNode* temp = tail->next;
        do{
            cout << temp->data << " -> ";
            temp = temp->next;
        }while(temp != tail->next);
        cout << "(back to the head) " << endl;

    }

    




};