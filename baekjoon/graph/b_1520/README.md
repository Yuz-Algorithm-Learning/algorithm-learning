## 1520 내리막 길

### 시도
* [b_1987](https://github.com/Yuz-Algorithm-Learning/algorithm-learning/tree/main/baekjoon/graph/b_1987)문제처럼 시도했으나, 시간 초과  
* 따라서, DP를 추가하여 메모이제이션을 통해 시간 단축  

### 풀이
```
1. dp[i][j]: (i, j) 위치에서 (M-1, N-1) 위치까지 도달할 수 있는 경로의 개수
2. 오른쪽, 아래, 왼쪽, 위 순서로 탐색
3. 이미 도달한 경우에는 탐색을 하지 않고 해당 위치의 dp에 담겨있는 값을 반환
```
