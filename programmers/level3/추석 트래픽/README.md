## 추석 트래픽

### 풀이
```c++
- hh:mm:ss.sss 형식을 초 단위(s)로 변경
- 끝시간(end_time) = hh * 3600 + mm * 60 + ss.sss 
- 시작시간(start_time) = 끝시간(end_time) - 처리시간(t) + 0.001

- lines는 끝시간 기준으로 정렬되어 있음
- vector<pair<double, double>> re_time; /* 시작시간, 끝시간 */

- 24 ~ 35: re_time[i]번 째를 무조건 포함했을 때의 최대 처리량 구하기
```
