#include <iostream>                                                              
#include <string>                                                                
#include <string.h>                                                              
#include <vector>    
#include <queue>
#include <deque>
using namespace std;
vector<string> input;

void compress(int startX, int startY, int size) 
{
    if (size >= 1) {
        bool isZero = true, isOne = true;
        for (int i = startX; i < startX + size; i++) {
            for (int j = startY; j < startY + size; j++) {
                if (input[i][j] == '1') {
                    isZero = false;
                }
                if (input[i][j] == '0') {
                    isOne = false;
                }
            }
        }
        if (isZero == true) {
            cout << "0";
        }
        else if (isOne == true ) {
            cout << "1";
        }
        else {
            cout << "(";
            compress(startX, startY, size / 2);
            compress(startX, startY + size / 2, size / 2);
            compress(startX + size / 2, startY, size / 2);
            compress(startX + size / 2, startY + size / 2, size / 2);
            cout << ")";
        }
    }
}

int main() {
    int N;
    cin >> N;
    input.assign(N, "");

    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    compress(0, 0, N);
    return 0;
}