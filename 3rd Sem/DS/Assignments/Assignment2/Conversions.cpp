// 1. Infix Expression

// Operator is between operands
// 👉 Example: A + B * C

// 2. Prefix Expression (Polish Notation)

// Operator comes before operands
// 👉 Example: + A * B C

// 3. Postfix Expression (Reverse Polish Notation)

// Operator comes after operands
// 👉 Example: A B C * +

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
// code to check precedence
int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}
// code to convert infix to postfix
void infixToPostFix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            res += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(c))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    cout << "Result: " << res << endl;
}

void infixToPreFix(string s)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            res += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(c))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    cout << "Result: " << res << endl;
}

void postFixToInfix(string s)
{
    stack<string> st;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            st.push(string(1, c));
        }
        else
        {
            if (st.size() < 2)
            {
                cout << "Invalid Expression!" << endl;
                return;
            }
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            res = "(" + op1 + c + op2 + ")";

            st.push(res);
        }
    }
    if (!st.empty())
        cout << "Result: " << st.top() << endl;
    else
        cout << "Invalid Expression!" << endl;
}

void prefixToInfix(string s)
{
    reverse(s.begin(), s.end());
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (isalpha(c)) 
            st.push(string(1, c));
        else
        {
            if (st.size() < 2)
            {
                cout << "Invalid Expression!" << endl;
                return;
            }

            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string exp = "(" + op1 + c + op2 + ")";
            st.push(exp);
        }
    }

    if (!st.empty() )
        cout << "Result: " << st.top() << endl;
    else
        cout << "Invalid Expression!" << endl;
}

void postFixEvaluation(string exp){
    stack<int> st;
    int op1;
    int op2;
    int result;
    for (int i = 0; i < exp.size(); i++)
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
}

void prefixEvaluation(string exp){
    reverse(exp.begin(), exp.end());
    stack<int> st;
    int op1;
    int op2;
    int result;
    for (int i = 0; i < exp.size(); i++)
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
                op1 = st.top();
                st.pop();
                op2 = st.top();
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
}

int main()
{
    string exp = "A+(B*C)";
    infixToPostFix(exp);
    string exp2 = "(A+B)*C";
    infixToPreFix(exp2);
    string exp3 = "abc*+";
    postFixToInfix(exp3);
    string exp4 = "+-*AB/CDE";
    prefixToInfix(exp4);
    string exp5="23-4+567*+*";
    postFixEvaluation(exp5);
    string exp6="-+7*45+20";
    prefixEvaluation(exp6);
}
