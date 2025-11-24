#include <iostream>
#include <cctype>
#include "myStack.hpp"

using namespace std;

int main(){

    int res;
    Stack *st = new myStack();
    string s;

    do{
        cout << "Enter value: ";
        cin >> s;
        if(isdigit(s[0])){
            st->push(s);
        }else{
            char op = s[0];
    	    if(op == 'x'){
    	        break;
    	    }
    	    
    	    string sval1 = st->pop();
    	    string sval2 = st->pop();

            int val1 = stoi(sval1);
            int val2 = stoi(sval2);
    	   
    	    switch(op){
    	       case '+':
    	            res = val2 + val1;
    	            break;
    	       case '-':
    	            res = val2 - val1;
    	            break; 
    	       case '/':
    	            res = val2 / val1;
    	            break; 
    	       case '*':
    	            res = val2 * val1;
    	            break;   
    	       default:
    	            break;
    	    }
    	    
    	    st->push(to_string(res));
    	}

	} while (s != "x");

    cout << "Answer: " << st->top() << endl;
    
}