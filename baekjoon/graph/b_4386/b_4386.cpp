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

    int n;
    cin >> n;

    roots.resize(n);
    vector<pair<double, double>> v;
    for(int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }

    vector<pair<double, pair<int, int>>> v_info;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            double dis = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
            v_info.push_back({dis, {i, j}});
        }
    }
    sort(v_info.begin(), v_info.end());

    for(int i = 0; i < n; i++)
        roots[i] = i;

    double sum = 0;
    for(int i = 0; i < v_info.size(); i++) {
        int v1 = v_info[i].second.first;
        int v2 = v_info[i].second.second;

        if(find(v1) == find(v2)) continue;

        sum += v_info[i].first;
        merge(v1, v2);

        if(v_info.size() == n - 1)
            break;
    }

    cout.precision(3);
    cout << sum << '\n';
    return 0;
}