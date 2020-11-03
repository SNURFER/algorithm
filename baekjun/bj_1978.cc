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
int main(){

    int N;
    int inputNum;
    int ans = 0;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> inputNum;
        if(inputNum == 1){
            ans++;
            continue;
        }
        for(int j = 1; j < inputNum; j++){
            if(inputNum % j == 0 && j != 1){
                ans++;
                break;
            }
        }
    }
    cout << N - ans;
	return 0;
}