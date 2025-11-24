#include <iostream>
#include <sstream>
#include <cctype>
#include "stack2.hpp"

using namespace std;

int evaluatePostfix(string str){
    Stack st;

    for(char c : str){
        if(c == ' '){
            continue;
        }
        if(isdigit(c)){
            st.push(c - '0');
        }else{
            int val1 = st.pop();
            int val2 = st.pop();

            switch(c){
                case '+':
                    st.push(val2 + val1);
                    break;
                case '-':
                    st.push(val2 - val1);
                    break;
                case '*':
                    st.push(val2 * val1);
                    break;
                case '/':
                    st.push(val2 / val1);
                    break;
                case '^':
                    st.push(pow(val2, val1));
                    break;
                default:
                    cout << "Invalid operator: " << c << endl;
                    break; 
            }
        }   
    }

    return st.pop();

}

int main(){

    string str;
    cout << "Enter a postfix expression: ";
    getline(cin, str);

    int result = evaluatePostfix(str);
    cout << "The result is: " << result << endl;


}