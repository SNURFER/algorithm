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
vector<long long> dp(10, 1);
vector<long long> preVal(10, 1);

void calEasyStep(int n) 
{
    if(n == 1) return;
    for (int i = 2; i < n + 1; i++) {
        dp[0] = preVal[1] % 1000000000;
        dp[1] = preVal[0] % 1000000000 + preVal[2]% 1000000000;
        dp[2] = preVal[1]% 1000000000 + preVal[3]% 1000000000;
        dp[3] = preVal[2]% 1000000000 + preVal[4]% 1000000000;
        dp[4] = preVal[3]% 1000000000 + preVal[5]% 1000000000;
        dp[5] = preVal[4]% 1000000000 + preVal[6]% 1000000000;
        dp[6] = preVal[5]% 1000000000 + preVal[7]% 1000000000;
        dp[7] = preVal[6]% 1000000000 + preVal[8]% 1000000000;
        dp[8] = preVal[7]% 1000000000 + preVal[9]% 1000000000;
        dp[9] = preVal[8]% 1000000000;
        preVal = dp;
    }
}

int ans() 
{
    int answer = 0;
    for (int i = 0; i < 10; i++) {
        answer += dp[i];
    }
    return answer % 1000000000;
}

int main() {
    preVal[0] = 0;
    dp[0] = 0;
    int N;
    cin >> N;

    calEasyStep(N);
    cout << ans();
    
    return 0;
}