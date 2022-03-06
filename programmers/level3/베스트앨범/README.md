## 베스트앨범

### 비교 함수
[comp 함수 (map to vec) 방식](https://github.com/Yuz-Algorithm-Learning/algorithm-learning/tree/main/programmers/level2/튜플)

### 풀이
```c++
- unordered_map<string, int> genres_play;                 /* {장르, 장르별 재생횟수 합} */
- unordered_map<string, vector<pair<int, int>>> info;     /* key: 장르, value: {재생횟수, 인덱스} */

/* 장르별 재생횟수 합 기준으로 내림차순 */
bool genres_comp(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}
/* 장르별로 재생횟수 기준으로 내림차순 */
bool play_comp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
```