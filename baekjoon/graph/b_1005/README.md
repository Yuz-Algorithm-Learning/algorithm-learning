## 1005 ACM Craft

### 풀이
```
- vector<int> b_time: 각 건물당 건설에 걸리는 시간
- vector<vector<int>> info: 건물 간 건설 순서
  - Ex) A -> B -> C 순으로 건설 된다면, C -> B -> A 순으로 info 벡터에 저장
- vector<int> rst(n + 1): '건물 W'부터 '현재 건물' 까지 걸리는 최대 시간 저장 
```
