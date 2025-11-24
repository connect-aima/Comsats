//For a given postfix expression, use dynamic stack to evaluate a numerical result for given values of variables. 
#include <iostream>
#include <stack>
#include <cmath> // for pow()
using namespace std;

void postFixEvaluation(string s) {
    stack<int> st;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == ' ') continue;

        if (ch >= '0' && ch <= '9') {
            st.push(ch - '0'); // convert char digit to int
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (st.size() < 2) {
                cout << "Error: Not enough operands\n";
                return;
            }

            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            int result = 0;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': result = pow(operand1, operand2); break;
            }

            st.push(result);
        }
    }

    cout << "Result: " << st.top() << endl;
}

int main() {
    string postfix = "5 3 8 * + 6 2 / - 4 2 3 ^ * + 9 -";
    postFixEvaluation(postfix);
    return 0;
}
