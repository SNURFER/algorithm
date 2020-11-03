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
    int N, M;
    cin >> N >> M;
    vector<int> cardNum(N, -1);;
    for (int i = 0; i < N; i++) {
        cin >> cardNum[i];
    }

    int tmp;
    int ans = -1;
    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            for (int k = j+1; k < N; k++) {
                tmp = cardNum[i] + cardNum[j] + cardNum[k];
                if (ans < tmp && tmp <= M) {
                    ans = tmp;
                }
            }
        }
    }
    cout << ans;

    return 0;
}