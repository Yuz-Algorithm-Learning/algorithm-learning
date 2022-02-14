#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string p;
        cin >> p;

        int n;
        cin >> n;
        deque<string> dq;
        
        string num;
        cin >> num;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] == ',')
                num[i] = ' ';
        }
        num = num.substr(1);
        num.pop_back();

        stringstream ss(num);
        string tmp;
        while (ss >> tmp)
            dq.push_back(tmp);


        bool front = true;
        bool error = false;
        string result = "";
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                if (front)
                    front = false;
                else
                    front = true;
            }
            else {
                if (dq.empty()) {
                    error = true;
                    result = "error";
                    break;
                }
                else {
                    if (front)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
            }
        }

        if (!error) {
            result = "[";

            if (front) {
                for (int i = 0; i < dq.size(); i++)
                    result += (dq[i] + ",");

            }
            else {
                for (int i = dq.size() - 1; i >= 0; i--)
                    result += (dq[i] + ",");
            }
            
            if(!dq.empty())
                result.pop_back();

            result += "]";
        }

        cout << result << "\n";

    }
}
