#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;

string aFunc(string str) {
    str.pop_back();
    return str;
}

string bFunc(string str) {
    reverse(str.begin(), str.end());
    str.pop_back();
    return str;
}

void recursive(string str) {
    if (s.size() == str.size()) {
        if (s == str) {
            cout << 1 << "\n";
            exit(0);
        }
        return;
    }
    
    if (str.front() == 'B')
        recursive(bFunc(str));
    if (str.back() == 'A')
        recursive(aFunc(str));

    if (str.front() == 'A' && str.back() == 'B')
        return;

}

int main()
{
    cin >> s >> t; 
    recursive(t);

    cout << 0;
}