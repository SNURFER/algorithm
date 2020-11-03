#include <iostream>                                                              
#include <string>                                                                
#include <string.h>                                                              
#include <vector>    
#include <queue>
#include <deque>
using namespace std;

void merge(vector<int>& input, int startIdx, int endIdx, int middleIdx)
{
    vector<int> tmp;

    int i = startIdx, j = middleIdx + 1;

    while (i <= middleIdx && j <= endIdx) {
        if (input[i] < input[j]) {
            tmp.push_back(input[i]);
            i++;
        }
        else {
            tmp.push_back(input[j]);
            j++;
        }
    }
    while (i <= middleIdx) {
        tmp.push_back(input[i]);
        i++;
    }

    while (j <= endIdx) {
        tmp.push_back(input[j]);
        j++;
    }

    for (int i = startIdx; i <= endIdx; i++) {
        input[i] = tmp[i - startIdx];
    }
}

void mergeSort(vector<int>& input, int startIdx, int endIdx)
{
    if (startIdx == endIdx) {
        return;
    }

    int divIdx = (startIdx + endIdx) / 2;

    mergeSort(input, startIdx, divIdx);
    mergeSort(input, divIdx + 1, endIdx);

    merge(input, startIdx, endIdx, divIdx);
}

int main() {

    vector<int> sample = {6, 5, 3, 1, 8, 7/*, 2, 4*/};

    mergeSort(sample, 0, sample.size() - 1);


    for (int i = 0; i < sample.size(); i++) {
        cout << sample[i] << endl;
    }

    return 0;
}