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
    int A, B, V;
    cin >> A >> B >> V;
    int N = 0;
    N = (V - B - 1) / (A - B) + 1;
    cout << N;

    return 0;
}