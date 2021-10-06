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
vector<vector<long long> > dp;

long long calMinPrice(int sIdx, int eIdx, vector<long long> &data, long long &sum) {
    if (dp[sIdx][eIdx] != -1) {
        return dp[sIdx][eIdx];
    }

    else if (eIdx - sIdx == 1) {
        dp[sIdx][eIdx] = data[sIdx] + data[eIdx];
        sum += dp[sIdx][eIdx];
        return dp[sIdx][eIdx];
    }

    else {
        long long minSum = LLONG_MAX;
        for (int i = sIdx; i < eIdx; i++) {
            long long preSum = 0;
            minSum = min(minSum, calMinPrice(sIdx, i, data, sum + preSum) + calMinPrice(i + 1, eIdx, data, sum + preSum));
        }
        dp[sIdx][eIdx] = minSum;
        return dp[sIdx][eIdx];
    }

}

int main() {
    dp.assign(501, vector<long long>(501, -1));

    int caseNum, dataNum, tmp;
    vector<long long> data;
    data.push_back(0);
    cin >> caseNum;

    for (int i = 0; i < caseNum; i++) {
        cin >> dataNum;
        for (int j = 0; j < dataNum; j++) {
            cin >> tmp;
            data.push_back(tmp);
            dp[j + 1][j + 1] = tmp;
        }
        long long sum = 0;
        cout << calMinPrice(1, data.size() - 1, data, sum) << endl;
        data.clear();
    }

    return 0;
}