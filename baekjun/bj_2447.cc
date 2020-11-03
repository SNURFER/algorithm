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
void printArray(vector<vector<bool>> array, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j  < N; j++) {
            if (j == N - 1) {
                cout << "*" << endl;
            }
            else if (array[i][j] == true) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
    }
}

void fillArray(int N, int idx, int idy, vector<vector<bool> >& array) {
    if (N == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ( i == 1 && j == 1)
                    continue;
                array[idx + i][idy + j] = true;
            }
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1)
                    continue;
                fillArray(N / 3, idx + i*(N/3) , idy + j*(N/3), array);
            }
        }
    }
}

int main(){
      int N;
    cin >> N;
    vector<vector<bool>> array;
    array.assign(N, vector<bool>(N, false));
    fillArray(N, 0, 0, array);
    printArray(array, N);
}