## 9177 단어 섞기

### 풀이
```c++
queue<pair<int, int>> q;        /* first: s1의 인덱스, second: s2의 인덱스 */
vector<vector<bool>> visited;   /* visitied[s1의 인덱스][s2의 인덱스] 일 때의 방문 여부 */
```