## 짝지어 제거하기

### 풀이
```
1. 문자열 s의 첫 문자부터 2개씩 비교
1-1. 두 문자가 같다면, 인덱스에 2만큼 더함
1-2. 두 문자가 다르다면, 문자열 s의 idx 위치에 있는 문자를 tmp 문자열에 추가
2. tmp 문자열의 마지막 인덱스와 마지막 인덱스의 바로 전 인덱스 비교
2-1. 두 문자가 같다면, 두 문자를 제거
3. idx를 하나 증가
4. 문자 개수만큼 1-3번 반복
5. tmp size 비교
5-1. tmp size가 0이 아니라는 것은 지워지지 않고 남은 문자가 있다는 말  
     -> 즉, 짝지어 제거하지 못한 문자가 있다는 뜻이므로, 0 반환  
5-2. tmp size가 0이라는 것은 다 지워졌다는 의미이므로, 성공적으로 1을 반환
```
예시) "baabaa" 일 때,  
![예시](https://user-images.githubusercontent.com/57518908/127878221-65f55f00-f0c7-4aae-82a4-08da7df6779d.jpg)

### test case
|s|result|
|---|---|
|"baabaa"|1|
|"cdcd"|0|
|"caacabaabbbddaccfggf"|1|