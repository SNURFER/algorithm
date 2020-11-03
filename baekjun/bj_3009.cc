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
  int x1, y1, x2, y2, x3, y3;
  int x, y;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  x = (x1 - x2 == 0) ? x3 : x1 + x2 - x3;
  y = (y1 - y2 == 0) ? y3 : y1 + y2 - y3;
  cout << x << " " << y;

  return 0;
}