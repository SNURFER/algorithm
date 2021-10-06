#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int> > dp;

int main() {

    dp.assign(501, vector<int>(501, 0));
    int n;
    cin >> n;
    vector<vector<int> > triangle;
    triangle.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }

    int maxVal = 0;
    for (int i = 1; i <= n; i++) {
        maxVal = max(maxVal, dp[n][i]);
    }
     cout << maxVal;


    return 0;
}