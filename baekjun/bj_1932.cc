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
vector<vector<int>> triangle;
vector<vector<int>> dp;

int sumPath(int n, int idx) 
{
    if (dp[n][idx] != -1) {
        return dp[n][idx];
    }
    dp[n][idx] = max(sumPath(n - 1, idx - 1), sumPath(n - 1, idx)) + triangle[n][idx];

    return dp[n][idx];
}

int main() {
    int n;
    cin >> n;
    triangle.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>());
    int tmp;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < i + 1; j++) {
            cin >> tmp;
            triangle[i].push_back(tmp);
            dp[i].push_back(-1);
        }
    }

        dp[1][0] = triangle[1][0];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (sumPath(n, i) > ans) ? sumPath(n, i) : ans; 
        }
        cout << ans;

    return 0;
}