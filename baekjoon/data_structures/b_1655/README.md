## 1655 가운데를 말해요

### 풀이
- 넣을 때마다 정렬해야하는 부분에서 priority_queue 사용
  - 홀 짝 홀 짝 순으로 pq1 -> pq2 -> pq1 -> pq2 순으로 넣음
- pq1은 낮은 쪽(내림차순), pq2는 높은 쪽(오름차순)
  - pq1의 top(낮은 값들 중 가장 큰 수)과 pq2의 top(높은 값들 중 가장 작은 수)을 비교하여 pq1의 top이 더 큰 경우 체인지
```c++
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
```
