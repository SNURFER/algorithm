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
static vector<pair<int, int>> dp;

void func(int n){
    if (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            dp[i].first = dp[i - 1].first + dp[i - 2].first;
            dp[i].second = dp[i - 1].second + dp[i - 2].second;
        }
    }
    cout << dp[n].first << " " << dp[n].second << endl;
}

int main(){
    dp.assign(40, pair<int, int>(-1, -1));
    int N, n;
    cin >> N;
    dp[0].first = 1;
    dp[0].second = 0;
    dp[1].first = 0;
    dp[1].second = 1;
    for (int i = 0; i < N; i++) {
        cin >> n;
        func(n);
    }
    return 0;
}