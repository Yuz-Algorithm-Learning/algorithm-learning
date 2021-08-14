#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<bool> sticker(M);
    int not_move = 0;
    for (int i = 0; i < N; i++) {

        vector<int> tmp(M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &tmp[j]);
        }

        int kinds = 0, idx = -1;
        for (int j = 0; j < M; j++) {
            if (kinds > 1) {
                break;
            }
                
            if (tmp[j] > 0) {
                idx = j;
                kinds++;
            }
        }

        if (idx == -1)   /* 비어있는 상자 */
            not_move++;
        else {
            if (kinds == 1 && sticker[idx] == 0) {
                sticker[idx] = 1;
                not_move++;
            }
        }

    }

    int ans = N - 1 - not_move;
    if (ans < 0)
        printf("0");
    else
        printf("%d", ans);

}
