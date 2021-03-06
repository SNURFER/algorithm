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

int main(){
  int N;
  cin >> N;
  vector<long long> f(1000001, -1);
  f[1] = 1;
  f[2] = 2;
  for (int i = 3; i < N+1; i++){
    f[i] = (f[i-1] + f[i-2]) % 15746;
  }
  cout << f[N];
  return 0;
}