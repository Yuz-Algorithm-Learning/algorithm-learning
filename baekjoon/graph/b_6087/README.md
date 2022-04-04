## 6087 레이저 통신

### 풀이
- 방향 고려하는 BFS 문제!
    - **방향마다 mirror 개수 각각 구해주어야 함!**
```c++
/* first: - 방향, second: | 방향 */
vector<vector<pair<int, int>>> mirr(h, vector<pair<int, int>>(w, {987654321, 987654321}));
```
- `-` 방향에서 `|` 방향으로 or `|` 방향에서 `-` 방향으로 처럼 방향이 바뀔 때, 거울 개수 하나 증가시켜준 값을 mirr 벡터에 저장

