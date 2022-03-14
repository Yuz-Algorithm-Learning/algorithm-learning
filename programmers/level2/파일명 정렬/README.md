## 파일명 정렬

### 풀이
- HEAD -> NUMBER 순으로 정렬
```c++
/* HEAD, NUMBER, files의 index */
- vector<tuple<string, int, int>> info;
```

- stable_sort를 이용해서 두 파일의 HEAD 부분과, NUMBER의 숫자도 같을 경우, 원래 입력에 주어진 순서를 유지하도록 함
```c++
stable_sort(info.begin(), info.end(), comp);
```