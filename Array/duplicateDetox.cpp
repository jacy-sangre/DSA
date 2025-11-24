#include <iostream>
#include <unordered_set>
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

    unordered_set<int> seen;
    vector<int> res;

    for(int x : arr){
        if(seen.find(x) == seen.end()){
            seen.insert(x);
            res.push_back(x);
        }
    }

    cout << "Duplicate Detox: ";
    for(int x : res){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}