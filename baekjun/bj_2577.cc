#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){
    int a, b, c;
    int mul;
    int divNum = 10;
    vector<int> rt;
    vector<int> ct(10,0);

    cin >> a >> b >> c;
    mul = a * b * c;

    for (int i = 0; i < 10; i++)
    {
        rt.push_back((mul % divNum) / (divNum / 10));
        ct.at((mul % divNum) / (divNum / 10)) = ct.at((mul % divNum) / (divNum / 10)) + 1;
        mul -= mul % divNum;
        divNum *= 10;
        if(mul == 0)
            break;
    }
    int n = rt.size();
    for (int j = 0; j < 10; j++)
    {
        cout << ct.at(j) << endl;
    }
    return 0;
}
