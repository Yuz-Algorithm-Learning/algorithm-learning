#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> s1(N + 1);  // index: 스위치 번호, value: 위치
    int tmp;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tmp);
        s1[tmp] = i;
    }
    vector<int> s2(N + 1);  // 입력받는 순으로 저장
    for (int i = 1; i <= N; i++) {
        scanf("%d", &s2[i]);
    }

    // 시작 idx, 끝 idx 매핑
    vector<int> line(N + 1);
    for (int i = 1; i <= N; i++)
        line[s1[s2[i]]] = i;

    int idx = 0;
    vector<int> v;
    vector<int> line_idx(N + 1);

    v.push_back(line[1]);
    line_idx[1] = 0;

    for (int i = 2; i <= N; i++) {
        if (v.back() < line[i]) {
            v.push_back(line[i]);
            line_idx[i] = ++idx;
        }
        else {
            int l_idx = lower_bound(v.begin(), v.end(), line[i]) - v.begin();
            v[l_idx] = line[i];
            line_idx[i] = l_idx;
        }
    }

    int find = idx;
    vector<int> result;
    for (int i = N; i > 0; i--) {
        if (line_idx[i] == find) {
            result.push_back(s2[line[i]]);
            find--;
        }
        if (find == -1)
            break;
    }
    sort(result.begin(), result.end());

    printf("%d\n", idx + 1);
    for (int re : result)
        printf("%d ", re);
}