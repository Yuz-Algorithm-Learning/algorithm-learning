#include <iostream>
#include <vector>

using namespace std;

int employee[100001] = { 0 };

void dfs(vector<vector<int>>& classes, int c_idx) {
    for (int i = 0; i < classes[c_idx].size(); i++) {
        employee[classes[c_idx][i]] += employee[c_idx];
        dfs(classes, classes[c_idx][i]);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> classes(n + 1);

    int tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);

        if (tmp == -1)
            continue;

        // vector의 index는 직속 상사 번호, value는 직원 
        classes[tmp].push_back(i);
    }

    int employee_i, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &employee_i, &w);

        employee[employee_i] += w;
    }

    dfs(classes, 1);

    for (int i = 1; i <= n; i++)
        cout << employee[i] << " ";
}