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

  int M;
  int N;
  cin >> M >> N;
  vector<int> decimal(N + 1, true);
  decimal[1] = false;

  for(int i = 2; i * i <= N; i++){
    if(decimal[i] == true){
      int n = 2;
      while (n * i < N + 1) {
        decimal[n * i] = false;
        n++;
      }
    }
  }

  for (int i = 1; i < N + 1; i++){
    if(i >= M && decimal[i] == true)
      cout << i << '\n';
  }
  return 0;
}