## 가장 큰 정사각형 찾기

### 풀이
```
- 1이 나오면 자신의 왼쪽, 위, 대각선(왼쪽 위) 요소들 중 최소값을 구하고 + 1
```

### 순서
- 처음
| 0 | 1 | 2 | 3 |
|---|---|---|---|
| 0 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 
| 1 | 1 | 1 | 1 | 
| 0 | 1 | 1 | 0 |

- 두번째 줄
| 0 | 1 | 2 | 3 |
|---|---|---|---|
| 0 | 1 | 1 | 1 |
| 1 | **1** | **2** | **2** | 
| 1 | 1 | 1 | 1 | 
| 0 | 1 | 1 | 0 |

- 세번째 줄
| 0 | 1 | 2 | 3 |
|---|---|---|---|
| 0 | 1 | 1 | 1 |
| 1 | 1 | 2 | 2 | 
| 1 | **2** | **3** | **3** | 
| 0 | 1 | 1 | 0 |

- 네번째 줄
| 0 | 1 | 2 | 3 |
|---|---|---|---|
| 0 | 1 | 1 | 1 |
| 1 | 1 | 2 | 2 | 
| 1 | 2 | 3 | 3 | 
| 0 | **1** | **2** | **3** |