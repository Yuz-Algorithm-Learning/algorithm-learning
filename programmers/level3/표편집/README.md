## 표편집

### 연결 리스트 풀이
```c++
struct Node {
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next) : n(n), prev(prev), next(next) {}
};
```
