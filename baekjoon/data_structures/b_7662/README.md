## 7662 이중 우선순위 큐
```
알고리즘: priority queue, map  
```

### 내용
```cpp
priority_queue<int> max_pq: 내림차순 우선순위 큐  
priority_queue<int, vector<int>, greater<int>> min_pq: 오름차순 우선순위 큐   
map<int, int> data: 두 개의 큐에서 모두 처리 되도록 상태를 표시해주기 위함  
                        [key는 큐에 넣을 값, value는 해당 값의 개수]
```

### 풀이
```
- I: 2개의 큐에 각각 삽입하고, map에 해당 값 추가
- D: 먼저, map의 상태를 통해 이미 지워졌던 값이라면 값 제거 진행  
     큐가 비어있지 않다면 큐에서 해당 값 제거 및 map에서도 제거
```
