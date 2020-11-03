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
vector<vector<int>> sdkBoard;
vector<pair<int, int>> zeroIdxStack;
bool escapeFlag = false;

bool fillZeroAvailable(pair<int, int>& idx, int n)
{ 
//cross check
for (int i = 0; i < 9; i++) {
    if (sdkBoard[i][idx.second] == n) return false;
    if (sdkBoard[idx.first][i] == n) return false;
}

//find location in [3][3]
int row = idx.first / 3;
int column = idx.second / 3;

for (int i = row * 3; i < row * 3 + 3; i++) {
    for (int j = column * 3; j < column * 3+ 3; j++) {
        if (sdkBoard[i][j] == n) return false; 
    }
}

return true;
}

void sdkSolver()
{
    if (escapeFlag == true) return;
    if (zeroIdxStack.size() == 0) {
        for (int i = 0; i < 9; i++) {
            for  (int j = 0; j < 9; j++) {
                cout << sdkBoard[i][j] << " ";
            }
            cout << endl;
        }
        escapeFlag = true;
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (fillZeroAvailable(zeroIdxStack.back(), i) == true) {
            pair<int, int> tmp = zeroIdxStack.back();
            sdkBoard[tmp.first][tmp.second] = i;
            zeroIdxStack.pop_back();
            sdkSolver();
            sdkBoard[tmp.first][tmp.second] = 0;
            zeroIdxStack.push_back(tmp);
        }
    }
}

int main(){

    sdkBoard.assign(9, vector<int>(9, -1));
    pair<int, int> tmp;

    for (int i = 0 ; i < 9; i++) {
        for (int j = 0 ; j < 9; j++) {
            cin >> sdkBoard[i][j];
            if(sdkBoard[i][j] == 0) {
                tmp = make_pair(i, j);
                zeroIdxStack.push_back(tmp);
            }
        }
    }

    sdkSolver();

  return 0;
}