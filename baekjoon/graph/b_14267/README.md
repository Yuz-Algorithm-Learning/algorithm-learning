## 14267 회사 문화 1
```
알고리즘: DFS
```

### 시도
```
* 여러 번의 DFS 시도로 인한 시간 초과
* 해결: 한 번의 DFS를 시행하여 누적 값을 저장
```

### 풀이
```
1. classes 벡터의 index는 직속 상사의 번호, value는 직원 번호
2. 직원 번호 i에게 칭찬의 수치 w의 값을 저장
3. DFS를 이용해서 employee 배열에 칭찬 누적합 저장
```

![14267](https://user-images.githubusercontent.com/57518908/126177917-49a8e46b-cdbe-4700-8e3c-2d0036afe87f.jpg)