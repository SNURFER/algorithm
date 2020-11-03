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
vector<int> dp;

int makeOne(int n) 
{
    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = min({makeOne(n / 2) + n % 2 + 1, makeOne(n / 3) + n % 3 + 1, makeOne(n - 1) + 1});

    return dp[n];
}
int main() {
    int N;
    cin >> N;
    dp.assign(N + 1, -1);

    dp[1] = 0;
    dp[2] = 1;

    cout << makeOne(N);

    return 0;
}