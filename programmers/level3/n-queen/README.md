## n-queen

### 풀이
- 백트래킹!!
- 가로, 세로, 대각선 모두 같지 않아야 함

- 행(세로)을 기준으로 한 줄씩 찾기
```c++
v[y] = x    /* queen의 위치가 y 행 x 열에 위치함 */ 
```

- 이전 queen 들과 현재 좌표가 같은 열에 있는지, 대각선에 위치하는지 판단
```c++
v[y] == x || abs(x - v[y]) == abs(y - col)
```

