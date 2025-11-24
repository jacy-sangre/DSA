#include <iostream>
#include <unordered_set>

using namespace std;

int main(){

    string s;
    cout << "Enter a string: ";
    cin >> s;

    int res = 0;
    unordered_set<char> seen;
    for(char c : s){
        if(seen.count(c)){
            seen.erase(c);
            res += 2;

        }else{
            seen.insert(c);
        }
    }

    cout << (seen.empty() ? res : ++res) << endl;
}