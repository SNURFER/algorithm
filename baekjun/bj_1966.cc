#include <iostream>                                                              
#include <string>                                                                
#include <string.h>                                                              
#include <vector>    
#include <queue>
#include <deque>
using namespace std;

int main() {

    int testCaseNum, N, targetIdx, imp;
    cin >> testCaseNum;

    for (int i = 0; i < testCaseNum; i++) {
        priority_queue<int> printerQueue;
        queue<pair<int, int>> idxImpPair;

        cin >> N >> targetIdx;

        for (int j = 0; j < N; j++) {
            cin >> imp;
            printerQueue.push(imp);
            idxImpPair.push(make_pair(j, imp));
        }
        int tmpIdx, tmpImp, ans;
        ans = 0;
        while (printerQueue.size() > 0) {
            tmpIdx = idxImpPair.front().first;
            tmpImp = idxImpPair.front().second;
            idxImpPair.pop();

            if (printerQueue.top() == tmpImp) {
                printerQueue.pop();
                ans++;
                if (tmpIdx == targetIdx) {
                    cout << ans << endl;
                    break;
                }
            }
            else {
                idxImpPair.push(make_pair(tmpIdx, tmpImp));
            }
        }
    }
    return 0;
}