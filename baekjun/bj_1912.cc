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
vector<int> numArray;
vector<int> dp;

int continuousSum(int n)
{
    int maxVal = max(-1001, dp[1]);
    if (n == 1)
        return dp[1];

    for (int i = 2; i < n + 1; i++) {
        dp[i] = max(dp[i - 1] + numArray[i], numArray[i]);
        maxVal = max(dp[i], maxVal);
    }

    return maxVal;
}

int main() {
    int N;
    numArray.push_back(0);
    int tmp;
    cin >> N;
    dp.assign(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        numArray.push_back(tmp);
    }

    dp[1] = numArray[1];

    cout << continuousSum(N);

    return 0;
}