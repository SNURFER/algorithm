#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
vector<pair<int, int>> rowColVec;
vector<vector<int>> s;

int calSumMatrix(int sIdx, int eIdx, vector<pair<int, int>> &rowColVec, vector<vector<int>> &dp) {
    if (dp[sIdx][eIdx] != -1) {
        return dp[sIdx][eIdx];
    }
    else if (sIdx == eIdx) {
        return 0;
    }
    else {
        int minVal = INT_MAX;
        for (int i = sIdx; i < eIdx; i++) {
            minVal = min(minVal, calSumMatrix(sIdx, i, rowColVec, dp) + calSumMatrix(i + 1, eIdx, rowColVec, dp) +
                                     rowColVec[sIdx].first * rowColVec[i].second * rowColVec[eIdx].second);
        }
        dp[sIdx][eIdx] = minVal;
        return dp[sIdx][eIdx];
    }
}

int main() {
    //s[i][j] 는 index i 행렬 부터 index j 행렬 까지의 곱의합을 의미.
    s.assign(501, vector<int>(501, -1));

    int n;
    cin >> n;

    rowColVec.push_back(make_pair(0, 0));
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        rowColVec.push_back(make_pair(x, y));
    }

    cout << calSumMatrix(1, n, rowColVec, s) << endl;

    return 0;
}