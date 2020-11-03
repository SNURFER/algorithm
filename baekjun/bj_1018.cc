#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <vector>

using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<string> nmBoard(N, "");
    vector<vector<vector<int>>> diffMark3dVector;
    vector<vector<int>> diffMark2dVector;
    diffMark2dVector.assign(N, vector<int>(M, 0));
    diffMark3dVector.push_back(diffMark2dVector);
    diffMark3dVector.push_back(diffMark2dVector);

    for (int i = 0; i < N; i++) {
        cin >> nmBoard[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
        // [0][i][j] wbwb...
        // [1][i][j] bwbw...
            if ( (i + j) % 2 == 0) {
                if (nmBoard[i][j] != 'W') {
                    diffMark3dVector[0][i][j] = 1;
                    diffMark3dVector[1][i][j] = 0;
                }
                else {
                    diffMark3dVector[0][i][j] = 0;
                    diffMark3dVector[1][i][j] = 1;
                }
            }
            else {
                if (nmBoard[i][j] != 'B') {
                    diffMark3dVector[0][i][j] = 1;
                    diffMark3dVector[1][i][j] = 0;
                }
                else {
                    diffMark3dVector[0][i][j] = 0;
                    diffMark3dVector[1][i][j] = 1;
                }
            }
        }
    }

    int ans =  N * M;
    int tmp = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= N - 8; j++) {
            for (int k = 0; k <= M - 8; k++) {
                tmp = 0;
                for (int a = 0; a < 8; a++) {
                    for (int b = 0; b < 8; b++) {
                        tmp += diffMark3dVector[i][j + a][k + b];
                    }
                }
                ans = (tmp < ans) ? tmp : ans;
            }
        }
    }
    cout << ans;
    return 0;

}
