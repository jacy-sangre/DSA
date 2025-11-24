#include <iostream>
#include "stack.hpp"

using namespace std;

bool isBalanced(string str){
    Stack st;

    for(char c : str){
        if(c == '{' || c == '(' || c == '['){
            st.push(c);
        }else{
            if(st.isEmpty()){
                return false;
            }

            char top = st.pop();
            if((c == '}' && top != '{') || 
            (c == ')' && top != '(') || 
            (c == ']' && top != '[')){
                    return false;
                }
        }  

    }

    return st.isEmpty();

}

int main(){

    string str;
    cout << "Enter an expression: ";
    cin >> str;

    if(isBalanced(str)){
        cout << "The expression is balanced." << endl;
    }else{
        cout << "The expression is not balanced." << endl;  
    }

    return 0;

    

}