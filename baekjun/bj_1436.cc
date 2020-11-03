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
int shumNum(int n) {
    int num = 0;
    int nthNum = 0;
    string sigNum = to_string(666);
    while (true) {
        num++;
        if (string::npos != to_string(num).find(sigNum))
        {
            nthNum++;
        }
        if (n == nthNum)
            break;
    }
    return num;

}

int main(){
    int N;
    cin >> N;
    cout << shumNum(N);

    return 0;
}