## 방금그곡

### 풀이
- 콤마 기준으로 문자열 분류
```c++
while(getline(ss, str, ',')) {
    tmp.push_back(str);
}
```
- C#, D#, F#, G#, A# 
    - C# -> c, D# -> d 등으로 변환
- find 함수를 이용해 멜로디를 담은 m 문자열과 같은지 확인
```c++
if(tmp_3.find(m) != string::npos)
    v.push_back({t2 - t1, i, tmp[2]});
``` 