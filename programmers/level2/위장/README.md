## 위장

### 풀이
```
- map을 통해 종류에 따른 옷 개수 저장
- 한 종류당 옷을 고르는 방법 수: 옷 개수 + 1(옷을 고르지 않을 때)
- 따라서, A = 1, B = 3, C = 4 일 때, (1 + 1)(3 + 1)(4 + 1) = 40
    - 하루에 최소 한 가지 이상의 옷을 입으므로, 모든 옷을 고르지 않을 때인 1가지를 제외 -> 총 40 - 1 = 39가지
```
