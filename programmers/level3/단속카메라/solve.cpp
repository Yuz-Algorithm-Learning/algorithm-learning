#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    int out_car = routes[0][1];
    
    for(int i = 1; i < routes.size(); i++) {
        if(out_car < routes[i][0]) {
            answer++;
            out_car = routes[i][1];
        }
        if(routes[i][1] < out_car)
            out_car = routes[i][1];
    }

    return answer;
}