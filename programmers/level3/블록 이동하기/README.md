## 블록 이동하기

![블록 이동하기](https://grepp-programmers.s3.amazonaws.com/files/production/33f5c19ba6/052d3514-5fca-4b85-82aa-0f9eaefae0a3.jpg)

### 풀이
- [p1_y, p1_x], [p2_y, p2_x]: 각 좌표를 담아주는 구조체
```c++
typedef struct point{
    int p1_y;
    int p1_x;
    int p2_y;
    int p2_x;

    /* map에 사용하기 위해 필요한 operator */
    bool operator<(const point& other) const
    {
        if (p1_x != other.p1_x)
            return (p1_x < other.p1_x);
        if (p1_y != other.p1_y)
            return (p1_y < other.p1_y);
        if (p2_x != other.p2_x)
            return (p2_x < other.p2_x);
        if (p2_y != other.p2_y)
            return (p2_y < other.p2_y);
    }
} point;
```
- map을 이용하여 해당 두 좌표를 지났는지 방문 유무
```c++
- map<point, bool> visit;
```

- BFS를 이용한 탐색
```
주의점!! : 오른쪽, 아래, 아래로 회전 뿐만 아닌, 왼쪽, 위, 위로의 회전 또한 필요!!!
```

### test case
|parameters|return|
|---|---|
|[[0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1, 1, 0, 0], [1, 1, 1, 1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 1, 1, 1, 1, 0, 0], [0, 1, 1, 1, 1, 1, 1, 1, 1], [0, 0, 1, 1, 1, 1, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1, 1, 1, 0]]|33|
