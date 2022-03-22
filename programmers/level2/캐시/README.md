## 캐시

### 주의
- cacheSize가 0일 때, 만약 cities에 ["LA", "LA"]가 있는 경우
- cacheSize가 0이기 때문에 불러올 때마다 cache miss이므로 총 10초의 시간이 걸리지만, 정의해주지 않게 되면 6초의 시간이 걸리기 때문에 틀리게 됨
- cacheSize가 0일 때를 예외로 정의해주면 정답