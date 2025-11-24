#include <iostream>
#include "sNode.hpp"
using namespace std;

sNode* flip(sNode* head){
    
    sNode* curr = head;
    sNode* prev = nullptr;
    while(curr){
        sNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main(){
    int n, num;
    sNode* head = nullptr, *tail = nullptr;
    cout << "Enter number of elements: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Element " << i+1 << ": ";
        cin >> num;
        
        sNode* newNode = new sNode(num);
        if(!head) head = tail = newNode;
        else tail = tail->next = newNode;
    }

    cout << "Original linked list: ";
    sNode* temp = head;
    while(temp){
        cout << temp->data;
        if(temp->next) cout << " -> ";
        temp = temp->next;
    }

    cout << endl;

    cout << "Flipped linked list: ";
    temp = flip(head);

    while(temp){
        cout << temp->data;
        if(temp->next) cout << " -> ";
        temp = temp->next;
    }

    cout << endl;
}



