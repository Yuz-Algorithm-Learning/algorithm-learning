#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int _target;

void find_target(vector<int> numbers, int sum, int count) {
    if (count == numbers.size()) {
        if (sum == _target)
            answer++;
        return;
    }

    find_target(numbers, sum + numbers[count], count + 1);
    find_target(numbers, sum - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target) {
    _target = target;

    find_target(numbers, 0, 0);
    return answer;
}