## 합승 택시 요금

### 풀이
- 다익스트라를 이용해 한 점 기준 ~ 모든 점의 최단거리를 구함
- p -> q 와 q -> p 최단 거리가 같으므로, `start -> point + point -> a + point -> b 까지의 거리` 는 `point -> start + point -> a + point -> b` 거리와 같음
- 위의 상태를 기준으로 start, a, b 일 때 각각의 최단 거리를 구한 뒤 최소값 구하기