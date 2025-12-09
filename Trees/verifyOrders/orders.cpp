#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

bool verifyPost(vector<int>& pre){
    stack<int> st;
    int minValue = INT_MIN;
    
    for(int i = pre.size()-1; i >= 0; i--){
        int val = pre[i];
        if(val > minValue) return false;
        while(!st.empty() && val < st.top()){
            minValue = st.top();
            st.pop();
        }
        st.push(val);
    }
    
    return true;
}

bool verifyPre(vector<int>& pre){
    stack<int> st;
    int minValue = INT_MIN;
    
    for(int val : pre){
        if(val < minValue) return false;
        while(!st.empty() && val > st.top()){
            minValue = st.top();
            st.pop();
        }
        st.push(val);
    }
    
    return true;
}

int main(){
    
    int n, num;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> arr;
    
    
    cout << "Enter post-order: ";
    for(int i = 0; i < n; i++){
        cin >> num;
        arr.push_back(num);
    }
    
    cout << (verifyPost(arr) ? "VALID" : "INVALID");
}