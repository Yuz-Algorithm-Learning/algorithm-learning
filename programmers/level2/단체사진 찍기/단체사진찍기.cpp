#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    int num = 0;

    do {
        bool flag = true;
        
        for(int i = 0; i < n; i++) {
            
            int f1 = 0;
            int f2 = 0;
            
            for(int j = 0; j < friends.size(); j++) {
                if(friends[j] == data[i][0])
                    f1 = j;
                else if(friends[j] == data[i][2])
                    f2 = j;
            }
            
            int dis = ((f1 - f2 < 0)? f2 - f1 : f1 - f2) - 1;
            if(data[i][3] == '=') {
                if(dis != data[i][4] - '0') {
                    flag = false;
                    break;
                }
            } else if (data[i][3] == '<') {
                if(dis >= data[i][4] - '0') {
                    flag = false;
                    break;
                }
            } else if(data[i][3] == '>') {
                if(dis <= data[i][4] - '0') {
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
            answer++;

    } while (next_permutation(friends.begin(), friends.end()));
    
    return answer;
}