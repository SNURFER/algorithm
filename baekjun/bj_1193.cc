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

    int x = 1;
    int y = 1;
    int N;
    int n = 1;

    cin >> N;

    if(N == 1){
        cout << x << "/" << y << endl;
        return 0;
    }
    while(n < N){
        if(x == 1 && y % 2 == 1){
            y += 1;
            n++;
        }
        else if(y == 1 && x % 2 == 0){
            x += 1;
            n++;
        }
        else if((x + y) % 2 == 1){
            y -= 1;
            x += 1;
            n++;
        }
        else if((x + y) % 2 == 0){
            x -= 1;
            y += 1;
            n++;
        }
    }
    cout << x << "/" << y << endl;
        return 0;
}