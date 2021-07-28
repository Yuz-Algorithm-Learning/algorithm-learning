#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    int n;
    string str;
	while (t--) {
		scanf("%d", &n);
		vector<string> phone_num;
		string result = "YES";

		while (n--) {
			cin >> str;
			phone_num.push_back(str);
		}

		sort(phone_num.begin(), phone_num.end());

		for (int i = 1; i < phone_num.size(); i++) {
			if (phone_num[i - 1] == phone_num[i].substr(0, phone_num[i - 1].size())) {
				result = "NO";
				break;
			}
		}
        
        cout << result << "\n";
    }
}