#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int calTile(int n) {
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = (calTile(n - 1) + calTile(n - 2)) % 15746;
    return dp[n];
}

int main() {
    dp.assign(1000001, -1);
    dp[1] = 1;
    dp[2] = 2;

    int N;
    cin >> N;
    cout << calTile(N) << endl;

    return 0;
}