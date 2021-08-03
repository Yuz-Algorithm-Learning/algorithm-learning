#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<pair<int, int>> tree;

pair<int, int> init(int node, int start, int end) {
    if (start == end) {
        tree[node].first = tree[node].second = nums[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    pair<int, int> left = init(node * 2, start, mid);
    pair<int, int> right = init(node * 2 + 1, mid + 1, end);

    tree[node].first = min(left.first, right.first);
    tree[node].second = max(left.second, right.second);

    return tree[node];
}

pair<int, int> find(int node, int start, int end, int a, int b) {
    if (end < a || b < start)
        return make_pair(1000000001, -1000000001);

    if (a <= start && end <= b)
        return tree[node];

    int mid = (start + end) / 2;
    pair<int, int> left = find(node * 2, start, mid, a, b);
    pair<int, int> right = find(node * 2 + 1, mid + 1, end, a, b);
    
    return make_pair(min(left.first, right.first), max(left.second, right.second));
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    nums.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &nums[i]);

    int height = (int)ceil(log2(N));
    int seg_size = (int)pow(2, height + 1);

    tree.resize(seg_size);

    init(1, 0, N - 1);

    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);

        pair<int, int> rst = find(1, 0, N - 1, a - 1, b - 1);

        printf("%d %d\n", rst.first, rst.second);
    }
}