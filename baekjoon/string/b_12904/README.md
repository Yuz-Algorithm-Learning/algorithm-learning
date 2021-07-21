## 12904 A와 B

### 핵심
* 반대로 생각해보자!
    * **결과를 이용**해서 답을 찾아가는 문제
    * 이 문제와 비슷하게 유도하는 문제: [1300(K번째 수)](https://github.com/Yuz-Algorithm-Learning/algorithm-learning/tree/main/baekjoon/binary_search/b_1300)

### 풀이
```
* S를 이용해 T를 만드는 것이 아닌, 이를 반대로 생각하여 T를 가지고 S를 만들어내도록 유도
    * S문자열 뒤에 A를 추가 -> T문자열에서 A를 제거
    * S문자열을 뒤집고 뒤에 B를 추가 -> T문자열에서 B를 제거 후, 뒤집기
```
