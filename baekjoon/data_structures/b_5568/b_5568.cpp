#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for(int i = 0; i < n; i++)
        cin >> num[i];

    sort(num.begin(), num.end());
    set<string> set_num;
    do {
        string str_num = ""; 
        for(int i = 0; i < k; i++) {
            str_num += to_string(num[i]);
        }
        set_num.insert(str_num);
        
        reverse(num.begin() + k, num.end());
    } while(next_permutation(num.begin(), num.end()));

    cout << set_num.size() << '\n';
}