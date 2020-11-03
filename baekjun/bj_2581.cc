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
    int M;
    cin >> M >> N;
    vector<int> decimal(N - M + 1, true);
    for(int i = M; i < (N + 1); i++){
      if(i == 1){
        decimal[i - M] = false;
        continue;
      }
        for(int j = 1; j < i; j++){
            if(i % j == 0 && j != 1){
                decimal[i - M] = false;
                break;
            }
        }
    }
    bool findInitial = false;
    int sum = 0;
    int smallestDecimal = -1;
    for(int i = 0; i < (N - M + 1); i++){
        if(decimal[i] == true){
            if(findInitial == false){
                findInitial = true;
                smallestDecimal = i + M;
            }
            sum += i + M;
        }
    }
    if (smallestDecimal == -1)
      cout << smallestDecimal << endl;
    else {
      cout << sum << endl;
      cout << smallestDecimal << endl;
    }

  return 0;
}