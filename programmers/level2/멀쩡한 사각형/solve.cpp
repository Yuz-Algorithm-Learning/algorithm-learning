#include <cmath>

using namespace std;

long long solution(int w, int h) {
    long long answer = 0;
    
    for(int i = 1; i <= w; i++) {
        answer += (long long) h - ceil(h * (long long) i / (double) w); 
    }
    
    return answer * 2;
}