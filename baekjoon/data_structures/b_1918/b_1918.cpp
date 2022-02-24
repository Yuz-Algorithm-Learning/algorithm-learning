#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    string ans;
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {

        if ('A' <= str[i] && str[i] <= 'Z')
        { /* 피연산자 */
            ans += str[i];
        }
        else
        { /* 연산자 */
            switch (str[i])
            {
            case '(':
                st.push(str[i]);
                break;
            case '*':
            case '/':
                while (!st.empty() && (st.top() == '*' || st.top() == '/'))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(str[i]);
                break;
            case '+':
            case '-':
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(str[i]);
                break;
            case ')':
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); /* '(' 연산자 pop */
                break;
            }
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout << ans << "\n";
    return 0;
}