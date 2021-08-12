## 1810 징검다리 달리기 2

### 접근
```
1. pair를 사용하여 lower_bound, upper_bound 이용  
    1-1. 조건을 이용하고 싶을 땐 make_pair과 bool 타입의 comp 함수와 함께 사용    
    1-2. pair 의 first 기준으로 찾고싶을 땐 pair<type, type> 을 이용하여 사용  
2. tuple을 이용해 다익스트라 방식 사용
```

### 배열
```c++
1. map[y][x]: (x, y) 좌표 의미  
    - first: x 좌표  
    - second: (x, y) 좌표까지 가장 빠른 경로의 길이   
2. priority_queue  
    - tuple<int, int, double>: x좌표, y좌표, 현재 (x, y) 좌표까지 가장 빠른 경로의 길이  
```

### 풀이
```
1. 다익스트라 방식 사용  
    - 처음 (0, 0) 부터 시작하고, 현재 위치한 징검다리와 x좌표, y좌표 각각 차이가 2이하인 좌표를 구함  
    - 현재 위치한 징검다리와 x좌표, y좌표 각각 차이가 2이하인 좌표를 (a, b)라고 가정    
    - next_dis: dis + sqrt(pow(curr_x - map[y][x].first, 2) + pow(curr_y - y, 2));      
                (0, 0) ~ 현재 징검다리 좌표 + 현재 징검다리 좌표 ~ (a, b)   
    - map[b][a].second에 들어있는 경로의 길이와 위(next_dis)에서 구한 경로의 길이 중 더 짧은 경로의 길이를 map[b][a].second에 저장  
2. 결승선과 y좌표가 동일한 징검다리에 도달하면, 결승선을 통과한 것이므로 map[F]에 들어있는 경로들 중 최단 경로를 지정   
3. 최단 경로가 INF라면 불가능한 경우이기에 -1 출력하고, 아니라면 round를 이용하여 가장 빠른 경로의 길이를 소수 첫째 자리에서 반올림하여 출력
```
