#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void block_rotate(vector<pair<int, int>> &block) {   
    int max_y = 0;
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

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    vector<pair<int, int>> key_code;
    for(int i = 0; i < key.size(); i++) {
        for(int j = 0; j < key[i].size(); j++) {
            if(key[i][j])
                key_code.emplace_back(i, j);
        }
    }
    vector<pair<int, int>> lock_code;
    int lock_num = 0;
    int lock_y = lock.size();
    int lock_x = lock[0].size();
    
    for(int i = 0; i < lock.size(); i++) {
        for(int j = 0; j < lock[i].size(); j++) {
            if(!lock[i][j]) {
                lock_code.emplace_back(i, j);
                lock_num++;
            }
        }
    }
    
    if(lock_num == 0)
        return true;
    
    for(int r = 0; r < 4; r++) {
        for(int i = 0; i < lock_code.size(); i++) {
            for(int j = 0; j < key_code.size(); j++) {
                int y = lock_code[i].first - key_code[j].first;
                int x = lock_code[i].second - key_code[j].second;

                vector<pair<int, int>> tmp;
                int tmp_num = 0;
                bool is_key = true;
                for(int k = 0; k < key_code.size(); k++) {
                    int ny = key_code[k].first + y;
                    int nx = key_code[k].second + x;

                    if(ny >= 0 && ny < lock_y && nx >= 0 && nx < lock_x) {
                        if(!lock[ny][nx]) {
                            tmp_num++;
                        } else {
                            is_key = false;
                            break;
                        }
                    }
                }

                if(is_key && tmp_num == lock_num)
                    return true;
            }
        }

        block_rotate(key_code);
    }
    
    return false;
}