#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<pair<int, int>> house, chicken;
vector<bool> visit;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int tmp;
            scanf("%d", &tmp);

            if (tmp == 1)
                house.emplace_back(y, x);
            else if (tmp == 2)
                chicken.emplace_back(y, x);
        }
    }

    visit.resize(chicken.size(), true);
    for (int i = 0; i < chicken.size() - m; i++)
        visit[i] = false;

    vector<pair<int, int>> select;
    int result_min = 987654321;

    do {
        int result = 0;
        select.clear();

        for (int i = 0; i < chicken.size(); ++i) {
            if (visit[i]) {
                select.emplace_back(chicken[i].first, chicken[i].second); 
            }
        }

        for (int i = 0; i < house.size(); i++) {
            int min_dis = 987654321;
            for (int j = 0; j < select.size(); j++) {
                min_dis = min(min_dis, abs(house[i].first - select[j].first) + abs(house[i].second - select[j].second));
            }
            result += min_dis;
        }

        result_min = min(result_min, result);
        
    } while (next_permutation(visit.begin(), visit.end()));

    printf("%d", result_min);

}
