## 수식 최대화

### 풀이
```cpp
- 연산자와 피연산자 구분하여 각각 벡터 저장
    1. 피연산자: vector<long long> num
    2. 연산자: vector<char> oper
- next_permutation 을 이용해 연산자 순서 정렬
    - 연산자에 맞게 계산하고, 해당 위치의 두 피연산자를 지우고, 계산된 값을 저장
    - 사용된 연산자는 지우기
```
