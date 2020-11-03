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
vector<int> minLastHouseRSum(1001, -1);
vector<int> minLastHouseGSum(1001, -1);
vector<int> minLastHouseBSum(1001, -1);
vector<vector<int>> priceMap;

int minSum(int n)
{
    minLastHouseRSum[1] = priceMap[1][0];
    minLastHouseGSum[1] = priceMap[1][1];
    minLastHouseBSum[1] = priceMap[1][2];

    if (n > 1) {
        for (int i = 2; i < n + 1; i++) {
            minLastHouseRSum[i] = min(minLastHouseBSum[i - 1], minLastHouseGSum[i - 1]) + priceMap[i][0];
            minLastHouseGSum[i] = min(minLastHouseBSum[i - 1], minLastHouseRSum[i - 1]) + priceMap[i][1];
            minLastHouseBSum[i] = min(minLastHouseRSum[i - 1], minLastHouseGSum[i - 1]) + priceMap[i][2];
        }
    }

    return min(min(minLastHouseRSum[n], minLastHouseGSum[n]), minLastHouseBSum[n]);
}

int main() {
    int N;
    cin >> N;
    priceMap.assign(N + 1, vector<int>(3, -1));
    for (int i = 1; i < N + 1; i++) {
        cin >> priceMap[i][0] >> priceMap[i][1] >> priceMap[i][2];
    }

    cout << minSum(N);

    return 0;
}