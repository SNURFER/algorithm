#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void pathTracker(int startIdx, int destIdx, int num) {
    if (num > 0) {
        int midIdx = 6 - startIdx - destIdx;
        pathTracker(startIdx, midIdx, num - 1);
        cout << startIdx << " " << destIdx << "\n";
        pathTracker(midIdx, destIdx, num - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int N;
    cin >> N;
    cout << int(pow(2, N)) - 1 << "\n";
    pathTracker(1, 3, N);

    return 0;
}