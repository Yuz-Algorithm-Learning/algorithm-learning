#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());

    for(int i = 1; i < phone_book.size(); i++) {
        int length = min(phone_book[i - 1].size(), phone_book[i].size());
        bool is_same = true;

        for(int j = 0; j < length; j++) {
            if(phone_book[i - 1][j] != phone_book[i][j]) {
                is_same = false;
                break;
            }    
        }

        if(is_same) {
            answer = false;
            break;
        }
    }

    return answer;
}