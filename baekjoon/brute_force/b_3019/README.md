## 3019 테트리스

### 풀이
```c++
- lines 49~55: 테트리스 모양의 너비 구하기
- lines 57~62: 테트리스의 각 x좌표마다 y좌표의 최대값 구하기
   - 블록 3({0, 1}, {0, 2}, {1, 0}, {1, 1})인 경우,  
      1. x 좌표가 0 일 땐, y 좌표의 최대값은 1
      2. x 좌표가 1 일 땐, {0, 1}과 {1, 1} 중 최대값인 1
      3. x 좌표가 2 일 땐, y 좌표값은 0  
      따라서, bottom[0] = 1, bottom[1] = 1, bottom[2] = 0;
- lines 64~77: field의 높이와 위에서 구한 bottom의 높이를 더해서, 각 x의 위치마다 높이값이 동일한지 확인
   - 동일하다면, 알맞은 위치에 블록을 떨어뜨린 것
```

![테트리스](https://user-images.githubusercontent.com/57518908/156490490-ee8d8e46-9249-437e-9124-09b7d7ae86e3.jpeg)