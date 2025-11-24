#include <iostream>

using namespace std;

struct Node{
    int elem;
    Node* next;
    Node* prev;

    Node(int val){
        elem = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node *head = new Node(0);
Node *tail = new Node(0);
int size = 0;

void print();
void add(int n);
int remove(int n);
int removeNode(Node* n);
int removeAt(int pos);
void clear();           

int main(){

    head->next = tail;
    tail->prev = head;

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

int removeNode(Node* n){
    int ret = n->elem;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    size--;

    return ret;
}

void print(){
    if(size == 0){
        cout << "Empty" << endl;
        return;
    }
    Node* curr = head->next;
    cout << "Size: " << size << endl;
    cout << "From Head: ";
    while(curr != tail){
        cout << curr->elem;
        if(curr->next != tail) cout << " -> ";
        curr = curr->next;
    }
    cout << endl; 

    curr = tail->prev;
    cout << "From Tail: ";
    while(curr != head){
        cout << curr->elem;
        if(curr->prev != head) cout << " -> ";
        curr = curr->prev;
    }
    cout << endl;
}
void add(int n){
    Node* newNode = new Node(n);
    if(size == 0){
        newNode->next = tail;
        newNode->prev = head;
        head->next = newNode;
        tail->prev = newNode;
    }else{
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev = newNode;
    }  

    size++;
    return;
}
int remove(int n){

    if(size == 0) return -1;

    Node* curr = head->next;
    int i = 1;
    while(curr != tail){
        if(curr->elem == n){
            removeNode(curr);
            return i;
        }
        i++;
        curr = curr->next;
    }

    return -1;
}

int removeAt(int pos){
    if(pos < 1 || pos > size) return -1;

    
    Node* curr = head->next;
    for(int i = 1; i < pos; i++){
        curr = curr->next;
    }
    return removeNode(curr);     
}

void clear(){
    if(!head){
        cout << "Empty" << endl;
        return;
    }
    Node* curr = head->next;
    while(curr != tail){
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head->next = tail;
    tail->prev = head;
    size = 0;
}