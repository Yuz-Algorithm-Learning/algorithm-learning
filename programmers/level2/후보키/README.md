## 후보키

### 풀이
```c++
/* 후보키 저장 */
vector<string> minimality;
/* 유일성 검증 */
bool check_uniqueness(string col_str);
/* 최소성 검증 */
bool check_minimality(string col_str);
```

- '조합'을 이용해서 속성에 따른 경우의 수 찾기
- 유일성, 최소성 판단
    - 유일성
        - {학번, 이름, 전공}일 때 튜플이 {100, ryan, music}라고 가정하면 100ryanmusic 이라는 문자열로 만들기
        - map 을 이용해서 중복있는지 확인
    - 최소성
        - ₩저장되어 있는 후보키(minimality)₩들 중 ₩col_str₩에 포함되는게 있다면 최소성 성립하지 않음
        - 후보키에 ₩13₩ 이 저장 되어있을 때, ₩123₩ 은 최소성 성립하지 않음
