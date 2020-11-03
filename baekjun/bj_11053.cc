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
    return ans;
}

int main() {
    int tmp;
    cin >> N;
    dp.assign(N + 1, 1);
    arr.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    cout << calLis(N);

    return 0;
}