#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size()));
    
    for(int i = 0; i < arr2[0].size(); i++) {
        vector<int> a2;
        for(int j = 0; j < arr2.size(); j++) {
            a2.push_back(arr2[j][i]);
        }
        
        for(int ay = 0; ay < arr1.size(); ay++) {
            for(int ax = 0; ax < arr1[ay].size(); ax++) {
                answer[ay][i] += arr1[ay][ax] * a2[ax];
            }
        }
    }

    return answer;
}