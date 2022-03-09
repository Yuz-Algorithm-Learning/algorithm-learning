## 순위

### 풀이
- 플로이드-와샬 알고리즘
```c++
for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            if(i == k)
                continue;
            
            for(int j = 1; j <= n; j++) {
                if(j == k || i == j)
                    continue;

                ...
            }
        }
    }
}
```
- lines 30~40: 각 선수가 다른 선수들과 경기를 했는지 확인