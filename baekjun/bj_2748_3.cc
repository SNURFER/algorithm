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
  vector<long long> f(3, -1);
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i < N+1; i++){
    if (i % 3 == 0)
      f[0] = f[1] + f[2];
    else if (i % 3 == 1)
      f[1] = f[0] + f[2];
    else
      f[2] = f[0] + f[1];
  }
  cout << f[N%3];
  return 0;
}