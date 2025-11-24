#include <iostream>

using namespace std;

struct Node{
    int elem;
    Node* next;

    Node(int val){
        elem = val;
        next = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;
int size = 0;



void print();
void add(int n);
int remove(int n);
int removeNode(Node* pred, Node* curr);
int removeAt(int pos);
void clear();

int main(){

    int n, pos, res;
    char op;

    do{
        cout << "Op: ";
        cin >> op;

        switch(op){
            case 'p':
                print();
                break;
            case 'r':
                cin >> n;
                res = remove(n);
                if(res != -1) cout << "Removed at position " << res << endl;
                else cout << "Didn't remove anything" << endl;
                break;
            case 'R':
                cin >> pos;
                res = removeAt(pos);
                if(res != -1) cout << "Removed element " << res << endl;
                else cout << "Didn't remove anything" << endl;
                break;
            case 'a':
                cin >> n;
                add(n);
                break;   
            case 'c':
                clear();
                break;  
            case 'x':
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid operation" << endl;               
                  

        }
    }while(op != 'x');
}

void print(){
    if(!head){
        cout << "Empty" << endl;
        return;
    }
    Node* curr = head;
    cout << "Size: " << size << endl;
    while(curr){
        cout << curr->elem;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl; 
}
void add(int n){
    Node* newNode = new Node(n);
    if(!head) head = tail = newNode;
    else tail = tail->next = newNode;
    size++;

    return;
}
int remove(int n){

    if(!head) return -1;

    Node* curr = head;
    Node* prev = nullptr;
    int i = 1;
    while(curr){
        if(curr->elem == n){
            if(curr == head){
                head = head->next;
                if(!head) tail = nullptr;
            }else{
                prev->next = curr->next;
                if(curr == tail) tail = prev;
            }
            size--;
            delete curr;
            return i;
        }
        i++;
        prev = curr;
        curr = curr->next;
    }

    return -1;
}

int removeAt(int pos){
    if(pos < 1 || pos > size) return -1;

    if(pos == 1){
        int ret = head->elem;
        Node* toDelete = head;
        head = head->next;
        if(!head) tail = nullptr;
        
        size--;
        delete toDelete;
        return ret;
    }else{
        Node* curr = head;
        for(int i = 1; i < pos-1; i++){
            curr = curr->next;
        }
        
        if(curr){
            Node* toDelete = curr->next;
            int ret = toDelete->elem;
            curr->next = toDelete->next;
            if(!toDelete->next) tail = curr;
            delete toDelete;

            size--;
            return ret;

        }
    }
        
    return -1;
           
}

void clear(){
    if(!head){
        cout << "Empty" << endl;
        return;
    }
    
    Node* curr = head;
    while(curr){
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}