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

int solv(int k, int n){
    if(k == 0)
        return n;
    else if(n == 1)
        return 1;
    else
        return solv(k-1, n) + solv(k, n-1);
}

int main(){
    int T, k, n;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> k >> n;
        cout << solv(k, n) << endl;
    }
    return 0;
}