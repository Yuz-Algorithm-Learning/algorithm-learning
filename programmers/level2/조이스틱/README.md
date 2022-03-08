## 조이스틱

### 풀이
```c++
- 으!!아!! 좌우 움직이는 부분에서 반례 다양!
- vector<int> not_a; /* 0번째 자리 + A가 아닌 알파벳 자리 저장 */

- lines 11~22: 'A' 알파벳에서 만들어야하는 알파벳까지의 횟수
- lines 24~28: -> 이렇게 갔다가 <- 이렇게 가는 이동 길이
- lines 29~32: <- 이렇게 갔다가 -> 이렇게 가는 이동 길이
- not_a[not_a.size() - 1]: -> 이렇게 가는 경우
```

### test case
|name|return|
|---|---|
|"AABAAAAABBAA"|11|
|"AABABAAAAAABAA"|13|