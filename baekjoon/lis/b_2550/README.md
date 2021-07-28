## 2550 전구

### 알고리즘
```
LIS(Longest Increasing Subsequence): 가장 긴 증가하는 부분 수열 알고리즘을 이용   
    *주의*  벡터에 들어있는 값은 LIS를 이루는 요소와 무관  
            수열상에서 뒤에 있던 원소가 먼저 들어온 원소보다 lower_bound로 탐색 된 최적의 위치가 앞에 있을 수도 있기 때문  
            Ex) 1 4 5 2 3
```

### 생각
```
1. 선이 겹치지 않게 하기 위해선, 둘째 줄로 들어오는 스위치의 위치가 증가해야 함 -> LIS
2. 배열 
    - s1  
        - index: 스위치 번호  
        - value: 위치  
    - s2: 전구 입력 받는 대로  
    - line: 같은 번호의 위치 연결  
        - index: 스위치 번호 위치  
        - value: 전구 번호 위치  
3. line 배열의 LIS 알고리즘 적용
4. line_idx 배열의 마지막 인덱스부터 탐색  
```

### 풀이
![2550](https://user-images.githubusercontent.com/57518908/126972136-e3a64139-831f-4d00-9906-a172b4d1be52.jpg)
