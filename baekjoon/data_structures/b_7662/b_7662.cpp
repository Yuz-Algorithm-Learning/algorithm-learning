#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;

        int num;
        string type;
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        map<int, int> data;

        for (int j = 0; j < k; j++) {
            cin >> type >> num;

            if (type == "D") {
                if (num == 1) {
                    while (!max_pq.empty() && !data[max_pq.top()])
                        max_pq.pop();

                    if (!max_pq.empty()) {
                        data[max_pq.top()]--;
                        max_pq.pop();
                    }
                }
                else {
                    while (!min_pq.empty() && !data[min_pq.top()])
                        min_pq.pop();

                    if (!min_pq.empty()) {
                        data[min_pq.top()]--;
                        min_pq.pop();
                    }
                }
            }
            else {
                max_pq.push(num);
                min_pq.push(num);
                data[num]++;
            }
        }

        while (!max_pq.empty() && !data[max_pq.top()])
            max_pq.pop();
        while (!min_pq.empty() && !data[min_pq.top()])
            min_pq.pop();

        if (max_pq.empty() && min_pq.empty())
            cout << "EMPTY" << "\n";
        else
            cout << max_pq.top() << " " << min_pq.top() << "\n";

    }
}