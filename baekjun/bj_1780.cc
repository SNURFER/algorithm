#include <iostream>                                                              
#include <string>                                                                
#include <string.h>                                                              
#include <vector>    
#include <queue>
#include <deque>
using namespace std;
vector<vector<int>> input;
int countMiOne = 0;
int countOne = 0;
int countZero = 0;

void compress(int startX, int startY, int size) 
{
    if (size >= 1) {
        bool isZero = true, isOne = true, isMiOne = true;;
        for (int i = startX; i < startX + size; i++) {
            for (int j = startY; j < startY + size; j++) {
                if (input[i][j] != -1) {
                    isMiOne = false;
                }
                if (input[i][j] != 0) {
                    isZero = false;
                }
                if (input[i][j] != 1) {
                    isOne = false;
                }
            }
        }
        if (isZero == true) {
            countZero++;
        }
        else if (isOne == true ) {
            countOne++;
        }
        else if (isMiOne == true ) {
            countMiOne++;
        }
        else {
            compress(startX,                  startY,                    size / 3);
            compress(startX,                  startY + size / 3,         size / 3);
            compress(startX,                  startY + (2 * size) / 3,   size / 3);

            compress(startX + size / 3,       startY,                    size / 3);
            compress(startX + size / 3,       startY + size / 3,         size / 3);
            compress(startX + size / 3,       startY + (2 * size) / 3,   size / 3);

            compress(startX + (2 * size) / 3, startY,                    size / 3);
            compress(startX + (2 * size) / 3, startY + size / 3,         size / 3);
            compress(startX + (2 * size) / 3, startY + (2 * size) / 3,   size / 3);
        }
    }
}

int main() {
    int N;
    cin >> N;
    input.assign(N, vector<int>(N, -1)); 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
        }
    }
    compress(0, 0, N);

    cout << countMiOne << endl;
    cout << countZero << endl;
    cout << countOne << endl;
    return 0;
}