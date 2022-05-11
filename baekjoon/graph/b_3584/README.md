## 3584 가장 가까운 공통 조상

### 풀이
```c++
vector<int> n1_roots; /* 두 정점에 대해서 먼저 하나의 정점의 부모들을 담음 */
```
- find 함수를 이용해서 다른 정점에 대한 부모를 찾으며 같은 부모가 있으면 해당 부모 출력.
```c++
find(n1_roots.begin(), n1_roots.end(), tmp) != n1_roots.end())
```
