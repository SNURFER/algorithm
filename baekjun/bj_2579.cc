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
vector<int> stepPoints;
vector<int> dp;

int calSum(int n) {
    dp[0] = 0;
    dp[1] = stepPoints[1];
    dp[2] = stepPoints[1] + stepPoints[2];

    for (int i = 3; i < n + 1; i++) {
        dp[i] = max(dp[i - 2] + stepPoints[i], dp[i - 3] + stepPoints[i - 1] + stepPoints[i]);
    }
    return dp[n];
}

int main() {

    int N;
    cin >> N;
    stepPoints.assign(N + 1, -1);
    dp.assign(N + 1, -1);
    for (int i = 1; i < N + 1; i++) {
        cin >> stepPoints[i];
    }

    cout << calSum(N);

    return 0;
}