## 퍼즐 조각 채우기

### 변수
```c++
int board_size; // game_board 의 길이

/* 테이블 위에 높인 퍼즐 조각들이 담긴 배열, 현재 게임 보드 상태 */
vector<vector<int>> table, game_board;
/* 테이블의 각 퍼즐 조각들을 좌표 형식(pair<y좌표, x좌표>)으로 저장 ('모든' 퍼즐 조각 모양들을 저장) */
vector<vector<pair<int, int>>> tb_block;
/* 게임 보드의 빈 공간 좌표 저장: DFS 를 통해 찾은 인접한 빈 공간에 대한 정보 ('하나'의 빈 공간 퍼즐 저장) */
vector<pair<int, int>> gb_tmp;
/* 테이블에 있는 퍼즐이 게임 보드에 매칭 되었는지 확인 */
vector<bool> visit(tb_block.size());
```

### 함수 설명
```c++
/* 테이블에서 퍼즐 조각 찾는 함수 */
void table_dfs(int idx, int y, int x);
/* 게임 보드에서 하나의 인접한 빈 공간 찾는 함수 */
void gb_dfs(int y, int x);

/* 좌표들을 직~정사각형 틀에 맞추었을 때, 사각형의 왼쪽 상단의 좌표가 [0, 0] 좌표 기준이 되도록 옮기는 함수 */
void zero_loc(vector<pair<int, int>> &block);

/* 게임 보드에 속하는 빈 공간의 퍼즐 형태와 테이블의 퍼즐 형태이 같은지 확인하는 함수 */
bool is_puzzle_same(vector<pair<int, int>> a, vector<pair<int, int>> b)

/* 블록을 90도씩 회전하는 함수 */
void block_rotate(vector<pair<int, int>> &block) {
    
    /* block에 들어있는 좌표들을 직~정사각형 틀에 맞추었을 때, '세로 길이' */
    int max_y;
    ...

    /* 회전 부분 */
    for(int i = 0; i < block.size(); i++) {
        tmp.emplace_back(block[i].second, max_y - block[i].first - 1);
    }
}
```

### 풀이
```c++
- lines 105~116: 테이블의 각 퍼즐 모양을 찾아, [0, 0] 좌표 기준으로 표준화하고 정렬
- lines 122~123: 게임 보드의 빈 공간을 찾아, [0, 0] 좌표 기준으로 표준화

- lines 125~144
    - 위에서 게임 보드의 빈 공간(gb_tmp)에 대한 정보를 정렬하고, 테이블의 퍼즐 모양과 똑같은게 있는지 확인 
    - same_puzzle
        - 똑같은 퍼즐이 있다면 해당 퍼즐 모양의 인덱스 저장
        - 똑같은 퍼즐이 없으면 -1 저장
    - 똑같은 부분이 없다면, 퍼즐을 회전(block_rotate)하여 회전한 모양과 같은지 확인 (네 방향에 대해 모두 확인)
```