## 14891 톱니바퀴

### 풀이
```c++
vector<int> w_top(5, 0);        // 각 톱니바퀴의 top 번호
vector<int> next_dir(5, 0);     // 다음 톱니바퀴들의 방향 표시 (0: 바뀌지 않음, 1: 시계 방향, -1: 반시계 방향)
```