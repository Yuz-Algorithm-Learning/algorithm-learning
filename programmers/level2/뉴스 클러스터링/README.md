## 뉴스 클러스터링

### 알고리즘
```c++
- Map 이용
- 개념
    - 대문자를 소문자로 바꾸어주는 함수: tolower();
    - 해당 문자열에 알파벳만 존재하는지 확인하는 함수: isalpha();
    - map 에서 중복 key 가 존재하는지 확인방법
        1. a.find(tmp) != a.end()   
          : 맵 'a' 에 tmp라는 key 가 존재
        2. a.find(tmp) == a.end()  
          : 맵 'a' 에 tmp 라는 key 가 존재하지 않음
    - map 'a' 의 key 와 value 확인 방식  
        for (map<string, int>::iterator iter = a.begin(); iter != a.end(); iter++) {
            cout << iter->first << ", " << iter->second << endl;
	    }
```

### 주의
```c++
- 교집합이 0이고 합집합도 0인 경우, 0 / 0 은 에러이기에 이 부분 예외처리
- J(A, B) = 1로 정의 
if(!_inter && !_union) {
    _inter = 1;
    _union = 1;
}
```
