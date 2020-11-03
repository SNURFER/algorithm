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

    int A, B, C;
    int ans;
    cin >> A >> B >> C;
    if(C <= B)
    {
        cout << -1;
        return 0;
    }
 
    cout << A / (C - B) + 1;

        return 0;
}