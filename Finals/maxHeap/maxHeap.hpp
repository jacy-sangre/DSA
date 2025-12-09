#include <iostream>
#include "maxHeapADT.hpp"

using namespace std;

class maxHeap : public maxHeapADT{
    int size;
    int cap;
    int* items;


    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
    int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

    bool hasLeftChild(int index) {return getLeftChildIndex(index) < size; }
    bool hasRightChild(int index) {return getRightChildIndex(index) < size; }
    bool hasParent(int index) {return getParentIndex(index) >= 0; }

    int leftChild(int index) {return items[getLeftChildIndex(index)]; }
    int rightChild(int index) {return items[getRightChildIndex(index)]; }
    int parent(int index) { return items[getParentIndex(index)]; }

    void decreaseCapacity(){
        if(size < (cap * 2.0) / 3){
            cap -= floor(cap * .20);
            
            if(cap < 5){
                cap = 5;
            }
            items = (int*)realloc(items, sizeof(int) * cap);
        }
    }

    void increaseCapacity(){
        if(size == cap){
            cap = ceil(cap * 1.5);
            items = (int*)realloc(items, sizeof(int) * cap);
        }
    }

    void swap(int firstIndex, int secondIndex){
        int temp = items[firstIndex];
        items[firstIndex] = items[secondIndex];
        items[secondIndex] = temp;
    }

    void poll(){
        items[0] = items[size-1];
        size--;
    }

    void heapifyUp(){
        int index = size-1;
        while(hasParent(index) && items[index] > parent(index)){
            swap(index, getParentIndex(index));
            index = getParentIndex(index);
        }
    }

    void heapifyDown(){
        int index = 0;
        while(hasLeftChild(index)){ 
            int biggerChildIndex = getLeftChildIndex(index);
            if(hasRightChild(index) && rightChild(index) > leftChild(index) ){
                biggerChildIndex = getRightChildIndex(index);
            }

            if(items[index] > items[biggerChildIndex]) break;
            else swap(index, biggerChildIndex);

            index = biggerChildIndex;
        }
    }

    string makeSpace(int num, string str){
        string res = "";
        for(int i = 0; i < num; i++){
            res += str;
        }   
        return res;
    }

    public:

    maxHeap(){
        size = 0;
        cap = 5;
        items = (int*)malloc(sizeof(int) * cap);
    }

    void add(int item){
        increaseCapacity();
        items[size++] = item;
        heapifyUp();
    }

    void removeMax(){
        poll();
        heapifyDown();
        decreaseCapacity();
    }

    
    void printGrid(){
        if(size == 0){
            cout << "Empty" << endl;
            return;
        }
     
        int height = floor(log2(size));
        int newSize = pow(2, height);

        cout << makeSpace(pow(2, height), "------") << endl;
 
        int count = 1;
        cout << makeSpace(pow(2, height) - 1, "   ") << items[0] << endl;
        
        for(int i = 1; i <= height; i++){
            int copy = count;
            cout << makeSpace(pow(2, height - i) - 1, "   ");
            for(int j = 0; j < pow(2, i); j++){
                string arrow = "/";
                if(copy % 2 == 0){
                    arrow = "\\";
                }
                if(copy >= size){
                    arrow = " ";
                }
                cout << " " << arrow << " " << makeSpace(pow(2, height - (i - 1)) - 1, "   ");
                copy++;
            }
            cout << endl;

            cout << makeSpace(pow(2, height - i) - 1, "   ");

            for(int j = 0; j < pow(2, i); j++){
                string space = " ";
                int str = items[count];
                if(count < size){
                    int str = items[count];
                    if(str > 9){
                        space = "";
                    }
                    cout << " " << str << space << makeSpace(pow(2, height - (i - 1)) - 1, "   ");
                } else {
                    cout << "   " << makeSpace(pow(2, height - (i - 1)) - 1, "   ");
                }         
                count++;
            }
            cout << endl;
            
        }
        cout << makeSpace(pow(2, height), "------") << endl;
    }

    


    

};