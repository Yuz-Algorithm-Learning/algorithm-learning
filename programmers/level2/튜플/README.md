## 튜플

### 풀이
```
- 문자열 중에 '숫자'인 부분만 뽑아서 map의 key 에 넣어주고, 해당 숫자가 나올때마다 value값 증가
- 가장 많이 나온 value 값 순서로 answer 벡터에 저장 
```

### 알고리즘
```c++
- map 의 value 기준으로 정렬할 때 (내림차순 기준)
    - map을 vector 형태로 전환  
        - map<int, int> m 형태로 저장되어 있을 때 
        - vector<pair<int, int>> vec_m(m.begin(), m.end());
    - value 값에 대한 비교 함수 작성
        bool comp(const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;     /* 내림차순(>), 오름차순(<) */
    - sort 함수를 이용해 정렬
        sort(vec_m.begin(), vec_m.end(), comp);
}
```