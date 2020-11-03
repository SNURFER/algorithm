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
vector<pair<int, int>> weightAndValue;
vector<vector<int>> dp;

int calMaxVal(int n, int maxWeight)
{
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < maxWeight + 1; j++) {
            if (weightAndValue[i].first <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weightAndValue[i].first] + weightAndValue[i].second);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][maxWeight];
}

int main() {
    int N, maxWeight;
    cin >> N >> maxWeight;

    dp.assign(N + 1, vector<int>(maxWeight + 1, 0));
    weightAndValue.push_back(pair<int, int>(0, 0));
    int tmpWeight, tmpValue;

    for (int i = 0; i < N; i++) {
        cin >> tmpWeight >> tmpValue;
        weightAndValue.push_back(pair<int, int>(tmpWeight, tmpValue));
    }

    cout << calMaxVal(N, maxWeight);

    return 0;
}