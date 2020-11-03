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
    int N, cal;
    cin >> N;
    for (int i = 1; i < (2 * N); i++){
        if(i > N){
            cal = N - (i - N);
        }
        else {
            cal = i;           
        }
        for (int j = 0; j < cal; j++){
            cout << "*";
        }
        cout << endl;
    }
	return 0;
}