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
vector<pair<int, int>> conferenceTable;

int calMaxConferenceNum()
{
    int ans = 0;
    int preEndTime = 0;
    for (auto iter : conferenceTable) {
        if (iter.first >= preEndTime) {
            ans++;
            preEndTime = iter.second;
        }
        else {
            continue;
        }
    }
    return ans;
}

bool compare(pair<int, int> lhs, pair<int, int> rhs) 
{
    if(lhs.second == rhs.second)
        return lhs.first < rhs.first;

    return lhs.second < rhs.second;
}

int main() {
    int N;
    cin >> N;

    int startTime, endTime;
    for (int i = 0; i < N; i++) {
        cin >> startTime >> endTime;
        conferenceTable.push_back(pair<int, int>(startTime, endTime));
    }

    sort(conferenceTable.begin(), conferenceTable.end(), compare);

    // for (auto iter : conferenceTable) {
    //     cout << iter.first << " " << iter.second << endl;
    // }

    cout << calMaxConferenceNum();


    return 0;
}