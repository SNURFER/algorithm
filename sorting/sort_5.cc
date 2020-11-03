#include <iostream>                                                              
#include <string>                                                                
#include <string.h>                                                              
#include <vector>    
#include <queue>
#include <deque>
using namespace std;

int calPivotIndex(vector<int>& input, int left, int right) {
    int pivotVal = input[right];
    int pivotIdx = left - 1;

    for (int i = left; i < right; i++) {
        if (input[i] <= pivotVal) {
            pivotIdx++;
            swap(input[pivotIdx], input[i]);
        }
    }

    swap(input[right], input[pivotIdx + 1]);
    return pivotIdx + 1;
}

void quickSort(vector<int>& input, int left, int right) {
    if (left < right) {
        int pivotIdx = calPivotIndex(input, left, right);
        quickSort(input, left, pivotIdx - 1);
        quickSort(input, pivotIdx, right);
    }
}

int main() {

    vector<int> sample = { 4, 3, 2, 7, 6, 5, 8, 1};
    // vector<int> sample = { 7, 2, 5, 1, 3, 4};
    quickSort(sample, 0, sample.size()- 1);

    for (int i = 0; i < sample.size(); i++) {
        cout << sample[i] << endl;
    }

    return 0;
}