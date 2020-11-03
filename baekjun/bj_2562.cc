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
    int temp;
    int max = 0;
    int idx = 0;
    for(int i = 0; i < 9; i++){
        cin >> temp;
        if(temp > max){
           max = temp;
            idx = i + 1;
        }
    }
    cout << max << endl;
    cout << idx << endl;
 
    return 0;
}
