#include <iostream>
#include "list.hpp"

using namespace std;

class arrayList : public List {
    int size = 0;
    int arr[5];

    public:
    void add(int num){
        if(size >= 5){
            cout << "Can't add anymore" << endl;
            return;
        }
        arr[size++] = num;
    }

    void print(){
        for(auto &n : arr){
            cout << n << " ";
        }
        cout << endl;
    }

    void remove(int num){
        if(size == 0){
            cout << "Can't remove anymore." << endl;
            return;
        }
        int index = 0;
        for(int i = 0; i < size; i++){
            if(num == arr[i]){
                index = i;
                break;
            }
        }
        
        for(int i = index; i < size-1; i++){
            arr[i] = arr[i+1];
        }
        arr[size-1] = 0;
        size--;

    }

    void addFirst(int n){
        if(size >= 5){
            cout << "Can't add anymore" << endl;
            return;
        }
        for(int i = size; i > 0; i--){
            arr[i]= arr[i-1];
        }
        arr[0] = n;
        size++;

    }
    void addLast(int n){
        if(size >= 5){
            cout << "Can't add anymore" << endl;
            return;
        }
        arr[size] = n;
        size++;
    }

   void addAt(int num, int pos){

        if(pos == size){
            arr[pos-1] = num;
        }else{
            for(int i = size; i >= pos; i--){
                arr[i] = arr[i-1];
            }
            arr[pos-1] = num;
            size++;
        }
    }

    void flip(){
        int left = 0, right = size -1;

        while(left < right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }

    int removeAll(int n){

        int count = 0;
        for(int i = 0; i < size; i++){
            if(arr[i] == n){
                if(i == size-1){
                    arr[size-1] = 0;
                }else{
                    for(int j = i; j < size-1; j++){
                        arr[j] = arr[j+1];
                    }
                    i--;
                }
                arr[size-1] = 0;
                size--;
                count++;
                  
            }
        } 

        return count;
    }




};