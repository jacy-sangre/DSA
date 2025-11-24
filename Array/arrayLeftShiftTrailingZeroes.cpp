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

    int shift;
    cout << "Enter number of shifts: ";
    cin >> shift;

    for(int i = 0; i < n - shift; i++){
        arr[i] = arr[i+shift];
    }

    for(int i = n - shift; i < n; i++){
        arr[i] = 0;
    }

    cout << "Left shifted array: ";
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;
}