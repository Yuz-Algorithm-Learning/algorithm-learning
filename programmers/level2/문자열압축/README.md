## 문자열 압축

### 풀이
```
1. 최대 압축 문자열 길이는 문자열 길이의 절반이므로, 최대 압축 단어(cut)를 문자열 길이의 절반으로 진행   
2. 문자열을 1개 단위로 자를 때부터 위에서 구한 최대 압축 단어길이만큼 모든 경우의 수를 수행
3. 단위로 자른 인접한 문자열들끼리 같은지 다른지 확인  
    같다면, 중복개수를 증가  
    다르다면, 기본으로 합계에 단위 개수만큼 더해주고, 앞서 중복인 문자열이 있었다면 중복 개수 구해준 수만큼 더해줌
4. 위와 같이 진행하고, 마지막으로 중복이 있는데 처리되지 않은 것은 처리하고, 문자열이 남았을 때는 그만큼 더 추가해줌
```

### 오류
```
- 12ab와 같이 ab가 12번 반복됐을 때, 두자리 수(12)임을 감안하지 못함  
    즉, 7ab, 5a와 같이 반복 횟수가 10미만일 때를 기준으로 코드를 구현함  
    해결: duple을 bool 타입이 아닌, int 형으로 바꿔서 중복 횟수를 구해줌
```

### test case
|s|result|
|---|---|
|"a"|1|
|"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"|4|
|"aabbaccc"|7|
|"ababcdcdababcdcd"|9|
|"abcabcdede"|8|
|"abcabcabcabcdededededede"|14|
|"xababcdcdababcdcd"|17|