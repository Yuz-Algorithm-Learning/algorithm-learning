#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> roots;

int find(int x) {
    if(roots[x] == x) return x;
    return roots[x] = find(roots[x]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if(n1 == n2) return;

    if(n1 < n2) roots[n2] = n1;
    else roots[n1] = n2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v(n + 1);
    roots.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
        roots[i] = i;
    }
    
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        
        merge(v1, v2);
    }

    vector<pair<long double, pair<int, int>>> v_info;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            long double dis = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
            v_info.push_back({dis, {i, j}});
        }
    }
    sort(v_info.begin(), v_info.end());

    long double sum = 0;
    int con = n - 1;
    for(int i = 0; i < v_info.size(); i++) {
        int v1 = v_info[i].second.first;
        int v2 = v_info[i].second.second;

        if(find(v1) == find(v2)) continue;

        sum += v_info[i].first;
        merge(v1, v2);
        con--;

        if(con <= 0)
            break;
    }

    cout << fixed;          /* fixed는 소수점 아래 이후부터 고정시키겠다는 표현 */
    cout.precision(2);      /* 출력되는 숫자의 자릿수를 결정 */
    cout << sum << '\n';

    return 0;
}