## 1039 교환

### 풀이
- 전체 다 구하기 -> 시간을 줄이기 위해 map을 이용해 방문 유무 체크
- `BFS`를 이용해서 경우의 수 구하기
  - 예시) n = 12345 라면,
  - 1번째 2번째 바꾸기, 1번째 3번째 바꾸기, 1번째 4번째 바꾸기, 1번째 5번째 바꾸기
  - 2번째 3번째 바꾸기, 2번째 4번째 바꾸기, 2번째 5번째 바꾸기
  - ... 4번째 5번째 바꾸기 까지 진행