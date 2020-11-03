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
static vector<long long> dp(100, -1);

long long func(int n){
  if (n == 0)
    return dp[0];
  if (n == 1)
    return dp[1];
  if (dp[n] != -1)
    return dp[n];

  dp[n] = func(n - 1) + func(n - 2);
  return dp[n];
}

int main(){
  int N;
  cin >> N;
  dp[0] = 0;
  dp[1] = 1;
  cout << func(N);
    return 0;
}