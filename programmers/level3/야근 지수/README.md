## 야근 지수

### 풀이
```c++
/* {작업 시간, 개수} | key를 기준으로 내림차순 */
map<int, int, greater<int>> time;

- 작업량이 가장 큰 것을 기준으로 1시간씩 사용
- 최대 작업 시간의 개수를 하나 줄이고, 해당 작업 시간보다 하나 적은 작업시간의 개수를 하나 늘려줌
- 해당 작업 시간의 개수가 0개일 경우 맵에서 삭제
```
![야근 지수](https://user-images.githubusercontent.com/57518908/157155427-fdcad453-e68d-4826-b27c-06a75abbae1c.png)

