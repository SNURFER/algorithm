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
int N;
vector<pair<int, int>> elecWire;
vector<int> dp;
vector<int> arr;
int calLis(int n) 
{
    for(int i = 1; i <= n; i++) {
        int lastVal = arr[i];
        for(int j = 1; j < i; j++) {
            int targetVal = arr[j];
            if(targetVal < lastVal) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans < dp[i]) ? dp[i] : ans;
    }
    return n - ans;
}

int main() {
    int tmp;
    int tmpA, tmpB;
    cin >> N;
    dp.assign(N + 1, 1);
    arr.assign(N + 1, 1);
    elecWire.assign(N + 1, pair<int, int>(0, 0));
    for (int i = 1; i <= N; i++) {
        cin >> tmpA;
        cin >> tmpB;
        auto tmpPair = make_pair(tmpA, tmpB);
        elecWire[i] = tmpPair;
    }

    sort(elecWire.begin(), elecWire.end());

    for (int i = 1; i <= N; i++) {
        arr[i] = elecWire[i].second;
    }

    cout << calLis(N);

    return 0;
}