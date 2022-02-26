#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    /* 대문자 -> 소문자 */
    for(int i = 0; i < str1.size(); i++)
        str1[i] = tolower(str1[i]);
    for(int i = 0; i < str2.size(); i++)
        str2[i] = tolower(str2[i]);
    
    /* map 으로 중복 처리 */
    map<string, int> a;
    int _a = 0;
    for(int i = 0; i < str1.size() - 1; i++) {
        string tmp = str1.substr(i, 2);

        if(isalpha(tmp[0]) && isalpha(tmp[1])) {
            _a++;

            if(a.find(tmp) != a.end()) { 
                a[tmp]++;
            } else {              
                a.emplace(tmp, 1);
            }
        }
    }
    map<string, int> b;
    int _b = 0;
    for(int i = 0; i < str2.size() - 1; i++) {
        string tmp = str2.substr(i, 2);

        if(isalpha(tmp[0]) && isalpha(tmp[1])) {
            _b++;
            if(b.find(tmp) != b.end()) {
                b[tmp]++;
            } else {                
                b.emplace(tmp, 1);
            }
        }
    }


    /* 교집합 */
    int _inter = 0;
    for (map<string, int>::iterator iter = a.begin(); iter != a.end(); iter++) {
		if(b.find(iter->first) != b.end()) {
            _inter += min(a[iter->first], b[iter->first]);
        }
	}

    /* 합집합 */
    int _union = _a + _b - _inter;

    /* 
        교집합이 0이고 합집합도 0인 경우, 0 / 0 은 에러이기에 이 부분 예외처리
        J(A, B) = 1로 정의 
    */
    if(!_inter && !_union) {
        _inter = 1;
        _union = 1;
    }
    
    return _inter * 65536 / _union;
}