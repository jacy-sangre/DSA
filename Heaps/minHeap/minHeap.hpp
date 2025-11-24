#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "minHeapADT.hpp"
#include <math.h>

using namespace std;

class minHeap : public minHeapADT{
    int cap;
    int size;
    int *items;

    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex)  { return 2 * parentIndex + 2; } 
    int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

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

    void heapifyUp(){
        int index = size-1;
        while(index > 0 && items[index] < items[getParentIndex(index)]){
            swap(items[index], items[getParentIndex(index)]);
            index = getParentIndex(index);
        }
    }

    void heapifyDown(){
        int index = 0;
        while(getLeftChildIndex(index) < size){
            int smallerChildIndex = getLeftChildIndex(index);
            if(getRightChildIndex(index) < size && items[getRightChildIndex(index)] < items[getLeftChildIndex(index)]){
                smallerChildIndex = getRightChildIndex(index);
            }
            
            if(items[index] <= items[smallerChildIndex]) break;

            swap(items[smallerChildIndex], items[index]);
            index = smallerChildIndex;
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
    minHeap(){
        cap = 5;
        size = 0;
        items = (int*)malloc(cap * sizeof(int));
    }

    void add(int item){
        increaseCapacity();
        items[size++] = item;
        heapifyUp();
    }

    int removeMin(){
        if(size == 0) return -1;
        int item = items[0];
        items[0] = items[size-1];
        size--;
        decreaseCapacity();
        heapifyDown();
        return item;
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