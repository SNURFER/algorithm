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

    vector<int> res(42,0);
    int tmp;
    int ret = 0;
    for (int i = 0; i < 10; i++){
        cin >> tmp;
        res.at(tmp % 42) += 1;
    }
    for (int j = 0; j < 42; j++){
        if(res[j] > 0){
            ret++;
        }
    }
    cout << ret;
	return 0;
}