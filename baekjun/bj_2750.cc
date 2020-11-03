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
void sort(vector<int> &vector) {
    for (int i = 0; i < vector.size()-1; i++) {
        int tmp = i;
        for (int j = i+1; j < vector.size(); j++) {
            if(vector[tmp] > vector[j]) tmp = j;
        }
        swap(vector[i], vector[tmp]);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> array(n, -1);;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    sort(array);

    for (int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }

    return 0;
}