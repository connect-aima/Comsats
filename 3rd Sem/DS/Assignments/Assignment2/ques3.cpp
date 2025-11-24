// A scientific calculator application developed for engineers must evaluate mathematical expressions entered in postfix (Reverse Polish)
// notation. Each expression may contain:
// • Single- or multi-digit operands (non-negative integers)
// • Arithmetic operators: +, -, *, /
// Design a stack-based evaluator that computes the result of such expressions.
// Example: Input → 23-4+567*+* | Output → 141
// The evaluator should process each character sequentially, pushing operands and applying operators as they appear.
#include <iostream>
#include <stack>
using namespace std;

int main()
{

    stack<int> st;
    string exp;
    int op1;
    int op2;
    int result;
    cout << "Enter Expression:" << endl;
    cin >> exp;
    int l = exp.size();
    for (int i = 0; i < l; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            int num = exp[i] - '0';
            st.push(num);
        }
        else
        {
            if (st.size() >= 2)
            {
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                if (exp[i] == '+')
                {
                    result = op1 + op2;
                    st.push(result);
                }
                if (exp[i] == '-')
                {
                    result = op1 - op2;
                    st.push(result);
                }
                if (exp[i] == '*')
                {
                    result = op1 * op2;
                    st.push(result);
                }
                if (exp[i] == '/')
                {
                    result = op1 / op2;
                    st.push(result);
                }
            }
        }
    }
    cout << "Result : " << st.top() << endl;

    return 0;
}

//  int num = 0;
//             while (i < l && isdigit(exp[i]))
//             {
//                 num = num * 10 + (exp[i] - '0');
//                 i++;
//             }
//             i--;
//             st.push(num);