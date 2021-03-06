## 15961 회전 초밥

### 배열
```
    - sushi: 입력 받는 초밥 번호 순서대로 저장  
    - sushi_num: 초밥 번호의 개수 저장  
    - is_sushi: 맨 처음 들어오는 k개 만큼의 초밥 번호 유무 
```
### 풀이
```
0. c는 무조건 손님이 먹을 수 있는 초밥이므로, 미리 저장  
    - sushi_num[c]++;  
    - is_sushi[c] = 1;  
    - sum = 1;   
1. 첫 회전[0, k)인 k개 만큼의 초밥 가짓수(sum)를 구함   
2. [n, n+k) 중에서 첫번째 index인 n을 빼고, n 초밥의 개수를 하나 감소
3. n 초밥의 개수가 0개라면, 해당 초밥 번호가 없는 것이므로 초밥 가짓수(sum)을 감소
4. 새로 넣는 초밥 번호가 0개라면 초밥 가짓수(sum) 증가 후, 해당 초밥 번호의 개수를 하나 증가   
5. 2~4을 반복하면서 초밥 가짓수의 최댓값을 구함
```

![15961](https://user-images.githubusercontent.com/57518908/127438234-d3fcb924-9627-4908-a755-fa13ea058cf8.jpg)

