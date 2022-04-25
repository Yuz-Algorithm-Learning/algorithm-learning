## 17825 주사위 윷놀이

### 풀이
```c++
int next_turn[33];  /* next_turn[현재 index 위치] = 다음 index 위치 */
int scores[33];     /* 해당 index 위치에 들어있는 점수 */
int num[10];        /* 주사위에서 나올 수 10개 */
int turn[33];       /* 파란색 칸에서 이동을 시작할 경우 파란색 화살표를 타야하므로, 파란색 칸으로 이동했을 때의 index 저장 */
bool visited[33];   /* 해당 칸을 노드가 방문하고 있는지 */
int node_loc[4];    /* 각 말의 좌표(index) 저장 */
```
![image](https://user-images.githubusercontent.com/57518908/165042666-841d4e11-0472-4490-b9b8-0446655b45b9.png)
