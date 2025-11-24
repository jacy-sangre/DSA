#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

bool checkHappyNumber(int n){

    unordered_map<int, int> map;

    while(n != 1){
        int temp = n; 
        int squareSum = 0;

        while(temp){
            squareSum += pow(temp % 10, 2);
            temp /= 10;
        }

        if(map.count(n)){
            return false;
        }
        map[n] = squareSum;
        n = squareSum;
    }

    return true;
}

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << (checkHappyNumber(n) ? "Happy Number" : "Not a Happy Number") << endl;
}
