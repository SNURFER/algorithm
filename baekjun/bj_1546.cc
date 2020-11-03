#include <iostream>                                                              
#include <algorithm>                                                             
#include <stdlib.h>                                                              
#include <vector>    
using namespace std;
int main(){

    int N;
    double sum = 0;
    double tmp;
    double max = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        if (tmp > max){
            max = tmp;
        }
        sum += tmp;
    }
    cout << (sum / max) * (100 / static_cast<double>(N));
	return 0;
}