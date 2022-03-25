## 섬 연결하기

### 풀이
- 그리디 + Union-Find
```c++
/* Union-Find */
for(int i = 0; i < n; i++)
        roots[i] = i;

int find(int x) {
	if (roots[x] == x) return x;
	return roots[x] = find(roots[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	roots[y] = x;
}
```

- 비용 기준으로 오름차순 정렬
- Union-Find 를 이용하여 사이클인지 아닌지 판단
    - 사이클일땐 선택하지 않음

![image](https://user-images.githubusercontent.com/57518908/160164564-cfb0c31b-a93d-478b-9eaa-9309fe4352d1.png)