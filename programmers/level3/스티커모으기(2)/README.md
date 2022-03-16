## 스티커모으기(2)

### 풀이
- 처음 인덱스에 해당하는 값을 포함했을 때, 포함하지 않았을 때로 나누어 진행
    - sticker[0]을 포함했을 때 (스티커 수가 8개라고 가정)
        - sticker[2] ~ sticker[6] 까지의 최대값
        - sticker[0] + 위에서 구한 최대값
    - sticker[0]을 포함하지 않았을 때
        - sticker[1] ~ sticker[7] 꺼지의 최대값
    - 위의 두 경우의 중 큰 수가 정답

```c++
- pair<int, int> st; 
    - first: 자기자신 포함 안할 때 (이전 것의 포함 안할때와 할 때 중 큰 값)    
    : st[i].first = max(st1[i - 1].first, st1[i - 1].second);
    - second: 자기자신을 포함할 때 (이전 것의 포함 안했을 때 + 자기자신)    
    : st[i].second = st1[i - 1].first + sticker[i];
```