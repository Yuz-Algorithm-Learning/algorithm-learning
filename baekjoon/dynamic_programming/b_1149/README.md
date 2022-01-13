## 1149 RGB 거리

### 풀이
```c++
1. sum[i][j]    
    - i: 집 인덱스, j or k: RGB 중 하나
    - 좌표 [i, j] 까지의 최소 거리 저장
2. 점화식
    - sum[i + 1][k] = min(sum[i][j] + rgb[i + 1][k], sum[i + 1][k]);
```