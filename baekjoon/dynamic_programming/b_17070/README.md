## 17070 파이프옮기기 1

### 비슷한 문제
- [프로그래머스 level3 등굣길](https://github.com/Yuz-Algorithm-Learning/algorithm-learning/tree/main/programmers/level3/등굣길)

### 구현
```c++
/* 각 좌표의 [가로: 0, 대각선: 1, 세로: 2] 저장 */
vector<vector<tuple<int, int, int>>> map(n, vector<tuple<int, int, int>>(n));

현재 좌표를 [y, x] 라고 가정
- 가로일 땐, [y, x-1] 좌표의 가로일 때(get<0>)와 대각선일 때(get<1>)를 더한 값 
- 대각선일 땐, [y-1, x-1] 좌표의 가로일 때(get<0>)와 대각선일 때(get<1>) 그리고 세로일 때(get<2>)를 더한 값 
    - 이때, 대각선일 때는 인접 세 칸이 모두 빈칸이어야 함을 고려해야함   
      : [y-1, x-1] 좌표일 때 기준으로 가로, 대각선, 세로 모두 빈칸(이동할 수 있는 칸)이어야 한다.
- 세로일 땐, [y-1, x] 좌표의 대각선일 때(get<1>)와 세로일 때(get<2>)를 더한 값 
```
![파이프옮기기1](https://user-images.githubusercontent.com/57518908/156704288-db6c856e-ce4b-428c-8913-33f19c1a86a1.png)

