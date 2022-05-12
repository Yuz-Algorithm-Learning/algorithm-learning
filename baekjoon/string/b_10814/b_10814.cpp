#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct info {
    int age, idx;
    string name;
};

bool comp(const info &a, const info &b) {
    if(a.age == b.age)
        return a.idx < b.idx;
    return a.age < b.age;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<info> v;
    for(int i = 0; i < n; i++) {
        int num;
        string str;

        cin >> num >> str;
        v.push_back({num, i, str});
    }
    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < n; i++) {
        cout << v[i].age  << " " << v[i].name << "\n";
    }
}