## 11660 구간 합 구하기 5

### 풀이
```c++
1. map[i][j]: (1, 1) 부터 (i, j) 까지의 구간 합을 저장
2. (x1, y1) 부터 (x2, y2) 까지의 합
   : map[x2][y2] - (map[x2][y1 - 1] + map[x1 - 1][y2] - map[x1 - 1][y1 - 1])
```