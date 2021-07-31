#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    
    if(s.size() == 1)
        return 1;
    
    int answer = 1001;
    
	int cut = 1;
	while (cut <= s.size() / 2) {

		int num = s.size() / cut - 1;
		int idx = 0;
		int sum = cut;
		int duple = 1;

		string before = s.substr(idx, cut);
		idx += cut;

		while (num--) {
			string str = s.substr(idx, cut);

			if (before == str)
				duple++;
			else {
                
				if (duple > 1) {
					sum += to_string(duple).length();
					duple = 1;
				}

				sum += cut;
			}

			before = str;
			idx += cut;

		}

		if (duple > 1) {
            sum += to_string(duple).length();
        }

		sum += s.substr(idx).length();

		if (answer > sum)
			answer = sum;

		cut++;
	}
    
    return answer;
}