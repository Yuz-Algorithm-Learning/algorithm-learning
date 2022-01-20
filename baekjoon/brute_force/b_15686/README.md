## 15686 치킨 배달

### 알고리즘
- [조합(Combination) 개념](https://ansohxxn.github.io/algorithm/combination/)


### 배열
1. vector<pair<int, int>> house, chicken
   - 집 좌표와 치킨의 좌표 저장 (y, x) 형태
2. vector<bool> visit
   - 치킨집 m개의 조합을 구하기 위함
   - 모든 조합을 구하기 위해 bool 배열 초기 상태가 **오름차순 정렬**이어야 함
    : 즉, false가 true 보다 앞에 와야 함 (true가 m개 존재)
    : EX) 5C2 일 때, visit 배열은 {false, false, false, true, true} 모양이 초기값
   - bool 배열을 바탕으로 next_permutation 연산을 수행하여 true가 되는 것에 대응함


### 풀이
```c++
1. 치킨집 m개의 조합을 구하여 select 벡터에 저장
2. 각 집마다 select 벡터에 저장된 치킨 집과의 거리 중 가장 짧은 치킨 거리를 min_dis 에 저장
3. 치킨집 m개의 조합 중 가장 짧은 치킨 거리를 result_min 에 저장
```