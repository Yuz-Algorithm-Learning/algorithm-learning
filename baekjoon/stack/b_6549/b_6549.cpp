#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    if (n == 0)
        return 0;

    while (n != 0) {
        vector<int> histo(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &histo[i]);

        long long max_rectangle = 0;
        stack<int> upper;
        for (int i = 0; i < n; i++) {
            while (!upper.empty() && histo[i] < histo[upper.top()]) {
                long long height = histo[upper.top()];
                upper.pop();

                int width = i;
                if (!upper.empty())
                    width = i - (upper.top() + 1);

                max_rectangle = max(max_rectangle, height * width);
            }

            upper.push(i);
        }

        while (!upper.empty()) {
            long long height = histo[upper.top()];
            upper.pop();

            int width = n;
            if (!upper.empty())
                width = n - (upper.top() + 1);

            max_rectangle = max(max_rectangle, height * width);
        }

        printf("%lld\n", max_rectangle);

        scanf("%d", &n);
    }

}
