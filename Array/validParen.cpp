#include <iostream>
#include <vector>
#include <stack>

using namespace std;


bool isValid(string str){

    stack<int> st;
    for(char c : str){
        if(c == '{' || c == '(' ||  c == '['){
            st.push(c);
        }else {
            if(st.empty()) return false;

            char top = st.top();
            st.pop();

            if(c == '}' && top != '{' || c == ']' && top != '[' || c == ')' && top != '(' ){
                return false;
            }
        }
    }

    return st.empty();

    
}

int main(){

    string paren;
    cout << "Enter either a parenthesis, bracket, or curly-bracket: ";
    cin >> paren;

    cout << (isValid(paren) ? "Valid" : "Not Valid") << endl;
   
}