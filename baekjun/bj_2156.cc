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
vector<long long> wineVol;
vector<long long> dp;
int N;

void calMaxWine(int n)
{
    if(n <= 2) return; 

    for (int i = 3; i <= n; i++) {
        dp[i] = max({dp[i - 3] + wineVol[i - 1] + wineVol[i], dp[i - 2] + wineVol[i], dp[i - 1]});
    }
}

int main() {
    int tmp;
    
    cin >> N;
    dp.assign(N + 1, 0);
    wineVol.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        wineVol.push_back(tmp);
    }

    dp[1] = wineVol[1];
    dp[2] = wineVol[1] + wineVol[2];
    calMaxWine(N);
    cout << dp[N];

    return 0;
}