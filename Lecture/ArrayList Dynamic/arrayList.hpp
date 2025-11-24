#include <iostream>
#include "list.hpp"
#include <cstdlib>
#include <cmath>

using namespace std;

class arrayList : public List{
    private:
    int* array;
    int size;
    int capacity;

    public:
    arrayList(){
        array = (int*)malloc(sizeof(int) * capacity);
        capacity = 5;
        size = 0;
    }

    void increaseCapacity(){
        if(size == capacity){
            capacity = ceil(capacity * 1.5);
            array = (int*)realloc(array, capacity * sizeof(int));
        }
    }

    void decreaseCapacity(){
        if(size <= (2 * capacity / 3)){
            capacity -= floor(capacity * .25); 
            if(capacity < 5){
                capacity = 5;
            }
            array = (int*)realloc(array, sizeof(int) * capacity);
        }
    }

    void print(){
        int i = 0;
        for(; i < size; i++){
            cout << array[i] << " ";
        }
        for(; i < capacity; i++){
            cout << '?' << " ";
        }
        cout << endl;
    }

    void add(int n){
        
        increaseCapacity();
        array[size++] = n;
    }

    int get(int pos){
        return array[pos-1];
    }

    int remove(int n){

        int pos;

        for(int i = 0; i < size; i++){
            if(array[i] == n){
                pos = i+1;
                for(int j = i; j < size-1; j++){
                    array[j] = array[j+1];
                }
                size--;
                break;
            }
        }

        decreaseCapacity();

        return pos;
    }

    void addAt(int n, int pos){
        
        increaseCapacity();
        for(int i = size; i > pos-1; i--){
            array[i] = array[i-1];
        }
        array[pos-1] = n;
        size++;
    }

    int removeAt(int pos){

        int res = array[pos-1];
        for(int i = pos-1; i < size-1; i++){
            array[i] = array[i+1];;
        }
        size--;
        decreaseCapacity();

        return res;
    }

    int removeAll(int n){

        int count = 0;
        int retCount = 0;
        for(int i = 0; i < size; i++){
            if(array[i] != n){
                array[count++] = array[i]; 
            }
        }
        
        retCount = size - count;
        size = count;
        decreaseCapacity();

        return retCount;
    }
    

    




};