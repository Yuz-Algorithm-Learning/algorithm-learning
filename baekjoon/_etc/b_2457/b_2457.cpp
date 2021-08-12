#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    map<pair<int, int>, pair<int, int>> date;
    int s_m, s_d, e_m, e_d;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &s_m, &s_d, &e_m, &e_d);

        /* 삽입 시 이미 키가 존재하는 경우 */
        if (date.insert({ {s_m, s_d}, {e_m, e_d} }).second == false) {
            if (date[{s_m, s_d}].first < e_m)
                date[{ s_m, s_d }] = { e_m, e_d };
            else if (date[{s_m, s_d}].first == e_m) {
                if (date[{s_m, s_d}].second < e_d) {
                    date[{ s_m, s_d }] = { e_m, e_d };
                }
            }
        }
    }

    int answer = 0;
    pair<int, int> start = { 3, 1 };
    pair<int, int> end = { 0, 0 };
	map<pair<int, int>, pair<int, int>>::iterator iter = date.begin();
    while (iter != date.end()) {
        if (iter->first.first < start.first || (iter->first.first == start.first && iter->first.second <= start.second)) {
            if (iter->second.first > end.first || (iter->second.first == end.first && iter->second.second > end.second)) {
                end.first = iter->second.first;
                end.second = iter->second.second;

                if (end.first > 11) {
                    printf("%d", ++answer);
                    return 0;
                }
            }
            iter++;
        }
        else {
            if (iter->first.first > end.first || (iter->first.first == end.first && iter->first.second > end.second)) {
                printf("%d", 0);
                return 0;
            }
            start = end;
            answer++;
        }
    }

    printf("%d", 0);
}