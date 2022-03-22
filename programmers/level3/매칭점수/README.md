## 매칭점수

### 변수 설정
```c++
struct info {
    int basic;              /* 해당 웹 페이지의 기본 점수 */
    double match;           /* 해당 웹 페이지의 매칭 점수 */
    vector<string> link;    /* 해당 웹 페이지의 외부 링크 주소 */
};

map<string, int> url;       /* 해당 웹 페이지의 링크 주소, 웹 페이지의 index */
map<int, info> url_info;    /* 웹 페이지의 index 에 대한 info 내용 */
```

### 풀이
- 알고리즘을 생각하는데에는 어렵지 않았지만, 고려해야하는 형태가 많아서 애먹음..
1. 해당 웹 페이지의 url 구하는 방법 [테스트 케이스 9번]
    - `<meta property="og:url"`  태그 내에 태그의 값 url을 구해야함
    - `https://` 형태로 시작해야함
    - `"/>` 형태로 끝나야함 
2. 한 웹페이지에서 모든 외부 링크 구하는 방법 [테스트 케이스 10번]
    - `<a href="https://` 형태를 가지며, 이 형태로 시작함
        - 다른 attribute가 주어지는 경우는 없으며 항상 href로 연결할 사이트의 url만 포함된다.
    - `">` 형태로 끝나야함
3. word 
    - body 부분에 해당하는 문자열 추출(body_str)
    - aba 일 때 올바른 검색어 
        - O: aba@aba, &aba@aba 등
        - X: abaaba, abafaba, ababa 등
    - `isalpha`를 이용해 알파벳이 아닌 모든 문자 기준으로 구분
        - 지금까지 만들어진 문자(cur)가 주어진 단어와 같은지 확인
