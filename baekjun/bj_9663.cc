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
int N;
int ans = 0;
int pos;
bool isQueenPosAvailable(int pos, vector<int>& lowDepthVector)
{
    int size = lowDepthVector.size();
    for ( int i = 0; i < size; i++)
    {
        if (lowDepthVector[i] == pos) return false;
        if (lowDepthVector[i] + (size - i) == pos) return false;
        if (lowDepthVector[i] - (size - i) == pos) return false;
    }
return true;
}

void backTracker(vector<int>& lowDepthVector)
{
    //end of backtracking
    if(lowDepthVector.size() == N) {
        lowDepthVector.pop_back();
        ans++;
        return;
    }
    for (int i = 0; i < N; i++) {
        pos = i + 1;
        if(isQueenPosAvailable(pos, lowDepthVector)) {
            lowDepthVector.push_back(pos);
            backTracker(lowDepthVector);
        }
    }
    lowDepthVector.pop_back();
}

int main() {
    // //unit test for isQueenPosAvailable
    // vector<int> temp; 
    // temp.push_back(2);
    // temp.push_back(4);
    // temp.push_back(1);
    // cout << "pos 1 : " << isQueenPosAvailable(1, temp) << endl;
    // cout << "pos 2 : " << isQueenPosAvailable(2, temp) << endl;
    // cout << "pos 3 : " << isQueenPosAvailable(3, temp) << endl;
    // cout << "pos 4 : " << isQueenPosAvailable(4, temp) << endl;

    cin >> N;
    vector<int> input;
    backTracker(input);
    cout << ans << endl;

    return 0;
}