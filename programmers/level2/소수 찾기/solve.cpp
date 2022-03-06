#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    if (num < 2) 
        return false;
    
	int a = sqrt(num);
	for (int i = 2; i <= a; i++) 
        if (num % i == 0) 
            return false;
    
	return true;
}

int solution(string numbers) {
    int answer = 0;
    
    map<int, bool> num;
    
    for(int m = 1; m <= numbers.size(); m++) {
        
        sort(numbers.begin(), numbers.end());
        
        do {
            string tmp = "";
            
            for(int i = 0; i < m; i++) {
                tmp += numbers[i];
            }
            
            if(is_prime(stoi(tmp))) {
                if(!num[stoi(tmp)]) {
                    answer++;
                    num[stoi(tmp)] = true;
                }
            }

            tmp = "";
            reverse(numbers.begin() + m, numbers.end());
            
        } while (next_permutation(numbers.begin(), numbers.end()));
    
    }

    return answer;
}