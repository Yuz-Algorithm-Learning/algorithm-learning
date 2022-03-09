#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int x = 1, n_tmp = n;
    while(1) {
        n_tmp = n_tmp >> 1;
        if(n_tmp != 1)
            x++;
        else
            break;
    }

    if(a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    } 
    
    int start = 0, width = n;
    while(x) {
        width = width >> 1;
        int middle = start + width;
        
        if(a <= middle && b > middle) {
            return x;
        } else {
            if(a > middle && b> middle)
                start += width;
        }

        x--;
    }

}