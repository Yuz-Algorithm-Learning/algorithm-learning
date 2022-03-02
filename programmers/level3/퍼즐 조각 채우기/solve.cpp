#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int board_size;
vector<vector<int>> table, game_board;
vector<vector<pair<int, int>>> tb_block;
vector<pair<int, int>> gb_tmp;

/* table 에서 block 찾기 */
void table_dfs(int idx, int y, int x) {
    table[y][x] = 2;
    tb_block[idx].emplace_back(y, x);

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || ny >= board_size || nx < 0 || nx >= board_size)
            continue;

        if(table[ny][nx] == 1) {
            table_dfs(idx, ny, nx);
        }
    }
}

/* game_board 에서 빈 공간 찾기 */
void gb_dfs(int y, int x){
    game_board[y][x] = 2;
    gb_tmp.emplace_back(y, x);

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= board_size || nx < 0 || nx >= board_size)
            continue;

        if(game_board[ny][nx] == 0) {
            gb_dfs(ny, nx);
        }
    }
}

/* 위치 0, 0 일 때의 기준으로 옮기기 */
void zero_loc(vector<pair<int, int>> &block) {
    int min_x = 987654321, min_y = 987654321;

    for(int i = 0; i < block.size(); i++){
        if(min_y > block[i].first)
            min_y = block[i].first;
        if(min_x > block[i].second)
            min_x = block[i].second;
    }

    for(int i = 0; i < block.size(); i++){
        block[i].first -= min_y;
        block[i].second -= min_x;
    }

}

/* game board 에 속하는 퍼즐과 table 의 퍼즐이 같은지 */
bool is_puzzle_same(vector<pair<int, int>> a, vector<pair<int, int>> b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i].first != b[i].first || a[i].second != b[i].second) {
            return false;
        }
    }
    return true;
}

/* 블록 회전 */
void block_rotate(vector<pair<int, int>> &block)
{   
    int max_y = 0;  /* 세로 길이 */
    vector<pair<int, int>> tmp;

    for(int i = 0; i < block.size(); i++){
        if(max_y < block[i].first)
            max_y = block[i].first;
    }
    max_y += 1;

    for(int i = 0; i < block.size(); i++) {
        tmp.emplace_back(block[i].second, max_y - block[i].first - 1);
    }

    block = tmp;
}

int solution(vector<vector<int>> gb, vector<vector<int>> tb) {
    int answer = 0;
    
    board_size = gb.size();
    game_board = gb;
    table = tb;
    
    int index = 0;
    for(int i = 0; i < table.size(); i++) {
        for(int j = 0; j < table[i].size(); j++) {
            if(table[i][j] == 1) {
                tb_block.push_back(vector<pair<int, int>>());
                table_dfs(index, i, j);
                zero_loc(tb_block[index]);
                sort(tb_block[index].begin(), tb_block[index].end());
                index++;
            }
        }
    }

    vector<bool> visit(tb_block.size());
    for(int i = 0; i < game_board.size(); i++) {
        for(int j = 0; j < game_board[i].size(); j++) {
            if(game_board[i][j] == 0) {
                gb_dfs(i, j);
                zero_loc(gb_tmp);

                int same_puzzle = -1;
                for(int r = 0; r < 4; r++) {
                    sort(gb_tmp.begin(), gb_tmp.end());
                    for(int p = 0; p < tb_block.size(); p++) {
                        if(!visit[p] && gb_tmp.size() == tb_block[p].size()) {
                            if(is_puzzle_same(gb_tmp, tb_block[p])) {
                                same_puzzle = p;
                                break;
                            }
                        }
                    }
                
                    if(same_puzzle != -1) {
                        visit[same_puzzle] = true;
                        answer += gb_tmp.size();
                        break;
                    } else {
                        block_rotate(gb_tmp);
                    }
                }
    
                gb_tmp.clear();
            }
        }
    }

    return answer;
}