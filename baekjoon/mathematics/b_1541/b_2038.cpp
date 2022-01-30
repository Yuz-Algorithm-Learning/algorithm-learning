#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int result = 0;
    string tmp = "";
    bool is_minus = false;

    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == '+' || str[i] == '-' || i == str.size()) {
            if (is_minus)
                result -= stoi(tmp);
            else
                result += stoi(tmp);

            tmp = "";

            if (str[i] == '-')
                is_minus = true;
        }
        else {
            tmp += str[i];
        }
    }

    cout << result;

}
