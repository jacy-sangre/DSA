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

    if(n < 2){
        cout << "Lucky number = " << arr[0] << endl;
        return 0;
    }

    unordered_map<int, int> freq;   
    for(int x : arr){
        freq[x]++;

    int maxCount = 1, res = -1;
    for(auto &p : freq){
        if(p.first == maxCount){
            res = -1;
        }else if(p.second > maxCount){
            maxCount = p.second;
            res = p.first;
        }
    }

    if(res == -1){
        cout << "(none)" << endl;
    }else{
        cout << "Lucky number = " << res << endl;
    }
    }
}