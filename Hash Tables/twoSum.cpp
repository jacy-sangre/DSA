#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> twoSum(vector<int> arr, int target){

    // {2, 7, 8, 9, 15} target = 17


    unordered_map<int, int> map;
    for(int i = 0; i < arr.size(); i++){
        int comp = target - arr[i];
        if(map.count(comp)){
            return {map[comp], i};
        }  
        map[arr[i]] = i;
    }

    return {};
}

int main(){

    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int target;
    cout << "Enter target sum: ";
    cin >> target;
    
    vector<int> res = twoSum(arr, target);
    cout << "Two Sum: {" << res[0] << ", " << res[1] << "} " << endl;
}
