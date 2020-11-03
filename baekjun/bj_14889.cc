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
vector<vector<int>> powerTable;
int N;
int minVal = 100 * 20;
vector<bool> usedIdx;
int startSum = 0;

int calLinkSynergy() 
{
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if(usedIdx[i] == true || usedIdx[j] == true) continue;
            ans += powerTable[i][j] + powerTable[j][i];
        }
    }
    return ans;
}

int calPlayerSynergyWithTeam(int playerNum)
{
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if(usedIdx[i] == true) {
            ans += powerTable[i][playerNum] + powerTable[playerNum][i];
        }
    }
    return ans;
}

void SALSolver(int pl, int n) 
{
    if(N / 2 == n)
    {
        int linkSum = calLinkSynergy();
        //check minimum value of past and new result 
        minVal = min(abs(linkSum - startSum) , minVal);

        return;
    }

    for (int i = pl; i < N; i++) {
        if(usedIdx[i] == false) {
            usedIdx[i] = true;
            startSum += calPlayerSynergyWithTeam(i);
            SALSolver(i, n + 1);
            usedIdx[i] = false;
            startSum -= calPlayerSynergyWithTeam(i);
        }
    }

}

int main () {

    cin >> N;
    powerTable.assign(N, vector<int>(N, -1));
    usedIdx.assign(N, false);

    for (int i = 0 ; i < N; i++) {
        for (int j = 0 ; j < N; j++) {
            cin >> powerTable[i][j];
        }
    }

    SALSolver(0, 0);
    cout << minVal;

    return 0;
}
