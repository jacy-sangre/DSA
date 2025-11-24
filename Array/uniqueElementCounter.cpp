#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    for(int x : arr){
        freq[x]++;
    }  

    int unique = 0;
    for(auto &p : freq){
        if(p.second == 1){
            unique++;
        }
    }

    cout << "Number of unique elements: " << unique << endl;


}