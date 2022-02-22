## 10026 적록색약

### 배열
```
- vector<vector<char>> map   
    - rgb 색 모두 표시
- vector<vector<bool>> rg  
    - rg 색깔만 true
- vector<vector<bool>> visit  
    - 방문유무
```

### 풀이
```
- 적록색약이 아닌 사람이 봤을 때의 구역의 수
    - 변수 rg1에 rg에 관련한 구역 개수를 저장
    - 변수 blue에 b의 구역 개수를 저장
- 적록색약인 사람이 봤을 때의 구역의 수
    - 변수 rg2에 r과 g 색깔을 같은 색깔로 보았을 때 구역 개수 저장
- type에 따라 DFS를 이용해 진행
```