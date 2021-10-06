#include <iostream>
#include <vector>
using namespace std;

vector<int> sumLastR(1001, -1), sumLastG(1001, -1), sumLastB(1001, -1);
vector<vector<int> > priceMap;


int main() {
    int houseNum;
    cin >> houseNum;
    priceMap.assign(houseNum, vector<int>(3, -1));

    for (int i = 0; i < houseNum; i++) {
        //RGB
        cin >> priceMap[i][0] >> priceMap[i][1] >> priceMap[i][2];
    }

    sumLastR[0] = priceMap[0][0];
    sumLastG[0] = priceMap[0][1];
    sumLastB[0] = priceMap[0][2];

    for (int i = 1; i < houseNum; i++) {
        sumLastR[i] = min(sumLastG[i - 1], sumLastB[i - 1]) + priceMap[i][0];
        sumLastG[i] = min(sumLastR[i - 1], sumLastB[i - 1]) + priceMap[i][1];
        sumLastB[i] = min(sumLastG[i - 1], sumLastR[i - 1]) + priceMap[i][2];
    }

    cout << min(sumLastB[houseNum - 1], min(sumLastG[houseNum - 1], sumLastR[houseNum - 1]));


    return 0;
}