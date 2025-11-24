#include <iostream>
#include <vector>
#include <unordered_map>

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

    int maxCount = 1, res = -1;
    for(auto &p : freq){
        if(p.second > n/2 && p.second > maxCount){
            maxCount = p.second;
            res = p.first;
        }
    }

    if(res == -1){
        cout << "No majority element" << endl;
    }else{
        cout << "Majority element = " << res << endl;
    }
}