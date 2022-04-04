## 2749 피보나치 수 3

### 풀이
- `피보나치수 주기` 사용
    - 주기의 길이를 p라고 할 때, n번째 피보나치수를 m으로 나눈 나머지는 n%p번째 피보나치수를 m으로 나눈 나머지와 같다.
    - `주기`는 m = 10^k (k>2) 일 때, 항상 `15*10^(k-1)` 이다.
    - 예시) m = 1,000,000 -> 10^6 이므로, k=6 이므로, 주기는 15*10^5 인 `1500000` 이다. 

- 참고 문제: [백준-피사노주기(9471)](https://www.acmicpc.net/problem/9471)