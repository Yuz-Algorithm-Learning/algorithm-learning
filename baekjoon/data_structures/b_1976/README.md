## 1976 여행 가자

### 풀이
- Union-Find
```c++
int find(int x) {
    if(roots[x] == x) return x;
    return roots[x] = find(roots[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(x < y) roots[y] = x;
    else roots[x] = y;
}
```
- 각 정점끼리 이어져 있는지 확인하면 되는 부분이므로, 그룹으로 나누어야함을 인지
- 각 정점의 루트 번호가 같다면 같은 그룹으로 인지 -> 여행할 수 있음