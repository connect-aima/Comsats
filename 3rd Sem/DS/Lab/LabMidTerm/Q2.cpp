// Q#2: Write a complete C++ program to evaluate a postfix (Reverse Polish Notation) expression using the Stack ADT.
// The expression string may include:
// •	Operators: +, -, *, /
// •	Operands: non-negative integers (single digits)
// During evaluation, the intermediate or final results may become two- or three-digit numbers.

// Task
// 1.	Read a postfix expression from the user as input.
// 2.	Use the STL stack (#include <stack>) for performing the required operations.
// 3.	Write a function named:
// 4.	int evaluate(string expr);
// that returns the evaluated result.
// 5.	Display the final output.

// Example
// Input:
// 23-4+567*+*
// Output:
// 141

// Instructions
// •	Use STL stack functions such as push(), pop(), top(), and empty().
// •	Assume the input expression is valid and contains only single-digit operands.
// •	Write a complete, properly structured, and well-commented C++ program.
#include <iostream>
using namespace std;
#include <stack>

void evaluate(string exp){
    stack<int> st;
    int res;
    int op1;
    int op2;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            int num = exp[i] - '0';
            st.push(num);
        }
        else
        {
            if (st.size() < 2)
            {
                cout << "invalid Expression.";
            }
            else if (exp[i] == '+')
            {
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                res = op1 + op2;
                st.push(res);
            }
            else if (exp[i] == '-')
            {
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                res = op1 - op2;
                st.push(res);
            }
            else if (exp[i] == '*')
            {
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                res = op1 * op2;
                st.push(res);
            }
            else if (exp[i] == '/')
            {
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                res = op1 / op2;
                st.push(res);
            }
        }
    }
    cout << "Result is " << st.top() << " ";
}

int main() {
    evaluate("23-4+567*+*");
    return 0;
}
