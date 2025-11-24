// Write an application using Stack that checks whether the entered string of brackets is balanced, e.g. 
// [{( )}]   is Balanced while {[( )] } is not Balanced because the priority of the pranthesis is not maintained.
#include <iostream>
#include <stack>
using namespace std;

class validParenthesis {
public:
    int priority(char ch){
        if (ch=='('|| ch==')')
        return 1;
        if (ch=='{'|| ch=='}')
        return 2;
        if (ch=='['|| ch==']')
        return 3;

        return 0;
    }
    bool isValid(string s) {
        stack<char>st;
        //looping over whole string
        for (int i=0;i<s.size() ; i++){
            //saving each character  in variable to performs checks on it.
            char ch=s[i];
            //checking for opening brackets 
            if(ch=='(' || ch=='{' || ch=='['){
                //checking for their priority if stack is not empty ,if priority is greater or equal then rejected
                if (!st.empty() && priority(ch) >= priority(st.top())) {
                    cout << "Invalid: Priority rule violated at '" << ch << "'\n";
                    return false;
                }
                //if stack is empty pushing value direct in stack
                st.push(ch);
            }else{
                // checking if any bracket is in stack or not (if there was all closing brackets so by default invalid)
                if(st.size()==0){
                    return false;
                }
                // comparing top of stack with variable if matched pop else return false
                if(st.top()=='(' && ch==')'
                 || st.top()=='{' && ch=='}' 
                 || st.top()=='[' && ch==']')
                 {
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        // if empty string return false
       return st.size()==0; 
    }
};

int main() {
    validParenthesis vp;
    cout << "OUTPUT :" << vp.isValid("{[()]}") << endl;
    cout << "OUTPUT :" << vp.isValid("[{()}]") << endl;
    return 0;
}