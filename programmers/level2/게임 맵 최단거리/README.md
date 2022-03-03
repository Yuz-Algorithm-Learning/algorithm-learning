## 게임 맵 최단거리

### 알고리즘
```c++
- BFS 탐색

/* 시작지점부터 각 좌표까지의 총 거리 저장 */
vector<vector<int>> dis(n, vector<int>(m));
/* y 좌표, x 좌표 대입 */
queue<pair<int, int>> q;
```
