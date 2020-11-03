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
vector<int> numArray;
vector<bool> usedMark;
int N = 0;
int M = 0;

void backTracker(int n) 
{
    if (M == n) {
        for (int i = 1; i <= M; i++) {
            cout << numArray[i] << " ";
        }
        cout << '\n';
    }

    for (int i = 1; i <= N; i++) {
        if (usedMark[i] == false) {
            usedMark[i] = true;
            numArray[n + 1] = i;
            backTracker(n + 1);
            usedMark[i] = false;
            numArray[n + 1] = -1;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    numArray.assign(N + 1, -1);
    usedMark.assign(N + 1, false);

    backTracker(0);

    return 0;
}