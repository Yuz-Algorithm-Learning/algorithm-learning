## 거리두기 확인하기

### 알고리즘
```
- 거리두기가 되지 않은 상황을 기준으로 false 반환
    - P -> P 와 P -> O -> P 총 두 경우 확인
- 대기실마다 P일 때를 기준으로 찾기
- type == true 는 이전이 P인 경우로, P -> O -> P 일 때를 찾기 위함
```
