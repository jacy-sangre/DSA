#include <iostream>
#include <vector>
#include <set>

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

    cout << "Gaps: ";
    set<int> s(arr.begin(), arr.end());

    //s.rbegin() = is reverse, so in a set it accesses the largest element!
    for(int i = *s.begin(); i <= *s.rbegin(); i++){ 
        if(s.find(i) == s.end()){
            cout << i << " ";
        }
    }
}

