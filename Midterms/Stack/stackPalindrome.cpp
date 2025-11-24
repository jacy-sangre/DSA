#include <iostream>
#include <string>
#include <array>
#include "myStack.hpp"

using namespace std;

bool isPalindrome(string s){
    Stack *st = new myStack();

    for(char c : s){
        st->push(string(1, tolower(c)));
    }

    string reversed = "";
    while(!(st->empty())){
        reversed += st->pop();
    }

    return s == reversed;
}

int main(){
    string s;
    cout << "Enter string ";
    getline(cin, s);
    
    if(isPalindrome(s)){
        cout << s << " is a palindrome!";
    }else{
        cout << s << "is not a palindrome";
    }
    cout << endl;
}