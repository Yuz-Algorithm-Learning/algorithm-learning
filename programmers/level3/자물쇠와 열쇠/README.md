## 자물쇠와 열쇠

### 풀이
- 주의!!
    - 주어진 lock이 전부 1인 경우에 key 랑 비교할 필요없이 True를 리턴하도록 예외처리!!

```c++
/* key 관련해서 회전하는 함수 */
void block_rotate(vector<pair<int, int>> &block);

- int lock_num;                         /* lock의 홈 개수 */
- vector<pair<int, int>> key_code;      /* key의 돌기 좌표 저장 */
- vector<pair<int, int>> lock_code;     /* lock의 홈 좌표 저장 */
```

- lines 51~54: 한 개의 lock 홈 좌표와 한 개의 key 돌기 좌표를 기준으로 둘 사이의 거리 차이를 구함
- lines 59~71
    - key_code에 들어있는 모든 좌표를 위에서 구한 거리 차이만큼 더해줌
    - key_code에 있는 좌표들이 lock의 좌표에 대응되게 구해줬으므로, 
        - lock이 비어있는 구간에 들어맞을 때마다 `tmp_num + 1`
        - lock이 비어있지 않은 곳에 들어맞을 땐 열쇠의 돌기와 자물쇠의 돌기가 만나는 것이므로 틀림
