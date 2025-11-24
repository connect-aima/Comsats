//Use dynamic stack and implement Infix to Postfix conversion algorithm and test it for various inputs.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void postFix(string s) {
    stack<char> st;
    string output = "";

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == ' ') continue;

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            output += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                output += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
                st.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!st.empty() && priority(ch) <= priority(st.top())) {
                output += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        output += st.top();
        st.pop();
    }

    cout << output << endl;
}

int main() {
    string infix = "A+(B*(C^(D-E/(F+G*H)))-I)*(J+K/(L-M^N))";
    postFix(infix);
    return 0;
}
