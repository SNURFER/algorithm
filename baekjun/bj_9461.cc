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
vector<long long> dp(101, -1);

long long P(int n) 
{
    if(dp[n] == -1) {
        dp[n] = P(n-1) + P(n-5); 
        return dp[n];
    }
    return dp[n];
}

int main() {

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    int N, T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << P(N) << endl;
    }

    return 0;
}