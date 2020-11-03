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
int bhh(int input) {
  int ans = input;
  while(input >= 1) {
    ans += input % 10;
    input = input / 10;
  }
  return ans;
}

int main(){
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0;  i < N; i++) {
    if (bhh(i) == N) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;

  return 0;
}