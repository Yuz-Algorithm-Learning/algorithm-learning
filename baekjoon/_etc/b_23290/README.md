## 23290 마법사 상어와 복제

### 문제 풀이
- 상어가 `연속해서 3칸 이동`한다. 상어는 현재 칸에서 상하좌우로 인접한 칸으로 이동할 수 있다. 연속해서 이동하는 칸 중에 격자의 범위를 벗어나는 칸이 있으면, 그 방법은 불가능한 이동 방법이다. `연속해서 이동하는 중에 상어가 물고기가 있는 같은 칸으로 이동하게 된다면,` 그 칸에 있는 모든 물고기는 격자에서 제외되며, 제외되는 모든 물고기는 물고기 냄새를 남긴다. 가능한 이동 방법 중에서 제외되는 물고기의 수가 가장 많은 방법으로 이동하며, 그러한 방법이 여러가지인 경우 사전 순으로 가장 앞서는 방법을 이용한다. 사전 순에 대한 문제의 하단 노트에 있다
    - 상어가 현재 위치한 자리에 물고기가 있을 때도 고려해주는 줄 착각함..
    - 현재 상어 위치에 있는 물고기는 고려하지 않고, `연속해서 3칸` 가는 부분에 물고기가 있으면 격자에서 제외하고 물고기 냄새 남김
