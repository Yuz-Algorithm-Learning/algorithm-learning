## 12100 2048(Easy)

### 풀이
- 모든 경우를 다 구해줌 (DFS로 진행)
- makeMap 함수: 현재 보드에서 방향에 따라 다음 보드를 반환함
   - 2개씩 비교하는 부분은 queue를 이용함
- 값이 가장 큰 값을 구해야하므로, 계산할 때마다 큰 값으로 갱신
