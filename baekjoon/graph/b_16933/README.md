## 16933 벽 부수고 이동하기 3

### 풀이
- BFS 로 풀되, visited 요소를 `k값` 기준으로 저장
- visited의 (y, x) 좌표에 있는 k값 < 현재 k값이 더 클 때
    - 현재 k값으로 변환 및 queue에 삽입
    - 기존에 있던 것이 더 빨리 도착했지만, 이후 k값이 모자라서 벽을 부수지 못하는 경우가 있을 수도 있기에 (예시 참조)

### 예시
```
2 4 2
0111
0110

답: 7
```
