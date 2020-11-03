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
  double r;
  cin >> r;
  cout.precision(6);
  cout.setf(ios::fixed);
  cout << PI * r * r << endl;
  cout << 2 * r * r << endl;
  return 0;
}