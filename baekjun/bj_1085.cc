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
  int x, y, w, h;
  cin >> x >> y >> w >> h;
  cout << min(min(x, y), min(w - x, h - y));
  return 0;
}