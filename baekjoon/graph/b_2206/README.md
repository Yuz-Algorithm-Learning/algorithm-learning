## 2206 벽 부수고 이동하기

### 풀이
- int map[MAX][MAX]: NxM 행렬 정보
- int rst[MAX][MAX]: 해당 칸까지의 총 경로
- bool visit[MAX][MAX][2]: 해당 칸의 방문 유무   
    - visit[y][x][0]: 벽을 부수지 않고 해당 칸 방문
    - visit[y][x][1]: 벽을 한 개 부수고 해당 칸 방문 
- queue<tuple<int, int, bool>> q -> <y위치, x위치, 벽 부순 유무>  
    - 0: 해당 칸 위치까지 벽을 부수고 이동한 적이 없음
    - 1: 해당 칸 위치까지 이미 벽을 한 개 부수고 이동함