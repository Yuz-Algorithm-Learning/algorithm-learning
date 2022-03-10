#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int citations_size = citations.size();
    
    sort(citations.begin(), citations.end());
    for(int i = 0; i < citations_size; i++) {
        int up = citations_size - i;
        int down = i;
        
        for(int j = citations[i - 1] + 1; j <= citations[i]; j++) {
            if(j <= up && down <= j)
                answer = j;
        }
    }
    
    return answer;
}