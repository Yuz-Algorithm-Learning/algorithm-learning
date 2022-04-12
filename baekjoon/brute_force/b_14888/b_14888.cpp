#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> num(n);
    for(int i = 0; i < n; i++)
        cin >> num[i];

    vector<int> op;
    for(int i = 0; i < 4; i++) {
        int tmp;
        cin >> tmp;
        
        if(tmp) {
            while(tmp--)    
                op.push_back(i);
        }
    }
    sort(op.begin(), op.end());

    int min_sum = INT_MAX;
    int max_sum = INT_MIN;
    do {
        int sum = num[0];

        for(int i = 0; i < op.size(); i++) {
            if(op[i] == 0) {
                sum += num[i + 1];
            } else if(op[i] == 1) {
                sum -= num[i + 1];
            } else if(op[i] == 2) {
                sum *= num[i + 1];  
            } else {
                sum /= num[i + 1];
            }
        }

        min_sum = min(min_sum, sum);
        max_sum = max(max_sum, sum);
    } while(next_permutation(op.begin(), op.end()));

    cout << max_sum << '\n' << min_sum << '\n';
}