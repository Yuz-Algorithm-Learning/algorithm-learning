#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int visit[MAX] = { 0 };
vector<int> grade[2][MAX];      // grade[0]: U, grade[1]: V

int DFS(int type, int x) {

    int result = 1;
    visit[x] = 1;

    for (auto value : grade[type][x]) {
        if (!visit[value])
            result += DFS(type, value);
    }

    return result;
}

int main()
{
    int N, M, X;
    int A, B;

    scanf("%d %d %d", &N, &M, &X);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);

        grade[0][B].push_back(A);       // U
        grade[1][A].push_back(B);       // V
    }

    int U = DFS(0, X);
    int V = N - DFS(1, X) + 1;

    printf("%d %d", U, V);

}