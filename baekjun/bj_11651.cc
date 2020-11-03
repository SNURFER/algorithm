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
int main() {
    int N;
    int x, y;
    cin >> N;
    cin.sync_with_stdio(false);
    vector<pair<int,int>> cordinate;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        cordinate.push_back(pair<int,int>(y, x));
    }
    sort(cordinate.begin(), cordinate.end());
    
    for (int i = 0; i < N; i++) {
        cout << cordinate[i].second << " " << cordinate[i].first << '\n';
    }

    return 0;
}