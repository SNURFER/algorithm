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
const double PI = acos(-1);
int main(){
  int T;
  int x1, y1, r1, x2, y2, r2;
  double d;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    if(d == 0 && r1 == r2) {
      cout << "-1" << endl;
      continue;
    }
    if((double)(abs(r1 - r2)) < d && d < (double)(r1 + r2)) {
      cout << "2" << endl;
      continue;
    }
    if((double)(abs(r1 - r2)) > d || (double)(r1 + r2) < d) {
      cout << "0" << endl;
      continue;
    }
    //if(abs(r1 - r2) == d || r1 + r2 == d) {
    else {
      cout << "1" << endl;
      continue;
    }
  }
  return 0;
}