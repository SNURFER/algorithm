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
int main()
{
    int T;
    double x, y;
    int ans;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> x >> y;

        //length
        y = y - x;
        ans = sqrt(y);

        if(ans * ans == y)
            cout << 2 * ans - 1 << endl;
        else if(ans * ans + ans >= y)
            cout << 2 * ans << endl;
        else
            cout << 2 * ans + 1 << endl;
    }
    return 0;
}