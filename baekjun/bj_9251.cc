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
string stringA;
string stringB;
vector<vector<int>> dp;
int numA;
int numB;

int findLCS(int nA, int nB)
{
    if (nA == 1 && nB == 1) {
        return dp[0][0];
    }

    for (int i = 1; i <= nA; i++) {
        for (int j = 1; j <= nB; j++) {
            if (stringA[i - 1 ] == stringB[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[nA][nB];
}

int main() {
    cin >> stringA;
    cin >> stringB;
    numA = stringA.size();
    numB = stringB.size();
    dp.assign(numA + 1, vector<int>(numB + 1, 0));

    if (stringA[0] == stringB[0]) {
        dp[1][1] = 1;
    }

    // else if (stringA[1] == stringB[0]) {
    //     dp[1][0] = 1;
    // }

    // else if (stringA[0] == stringB[1]) {
    //     dp[0][1] = 1;
    // }

    cout << findLCS(numA, numB);

    return 0;
}