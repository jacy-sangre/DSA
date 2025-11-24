#include "board.hpp"

using namespace std;

class Control {
    Board board[5];
    int size;

    public:
        void print(){
            for(int i = 0; i < 5; i++){
                if(i >= size){
                    cout << i+1 << ". (none)" << endl;
                }else{
                    cout << i+1 << ". " << board[i].name << ", " << board[i].course << " - " << board[i].score << endl;
                }
            }
            cout << endl;
        }
        bool add(Board b){
            
            if(size == 0){
                board[size++] = b;
                return true;
            }

            int pos = -1;
            for(int i = 0; i < size; i++){
                if(board[i].score < b.score){
                    pos = i;
                    break;
                }
            }

            if(pos == -1 && size < 5){
                board[size++] = b;
                return true;
            }

            if(pos == -1 && size >= 5) return false;

            for(int i = min(size, 4); i > pos; i--){
                board[i] = board[i-1];
            }
            board[pos] = b;
            
            if(size < 5) size++;

            return true;
        }

        int remove(int score){

            int count = 0;
            for(int i = 0; i < size; i++){
                if(board[i].score < score){
                    count++;
                }
            }
            size -= count;
            return count;
        }
};