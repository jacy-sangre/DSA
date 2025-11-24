#include <iostream>
#include <vector>
#include <unordered_set>

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

    unordered_set<int> seen;
    // for(int x : arr){
    //     if(seen.find(x) != seen.end()){
    //         cout << "Duplicate Found";
    //         return 0;
    //     }
    //     seen.insert(x);
    // }

    for(int x : arr){
        auto result = seen.insert(x);
        if(!result.second){
            cout << "Duplicate found";
            return 0;
        }
    }

    cout << "No duplicate found!";
}