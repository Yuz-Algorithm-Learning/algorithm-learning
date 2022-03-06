#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    while(arr.size() != 1) {
        int num1 = arr.back();
        arr.pop_back();
        int num2 = arr.back();
        arr.pop_back();
        
        int lcm_num = lcm(num1, num2);
        arr.push_back(lcm_num);
    }
    
    return arr[0];
}