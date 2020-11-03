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
    int n = 0;
    cin >> N;
    while(3 * (n - 1) * n + 1 < N){
        n++;
    }
    if (n == 0){
        cout << 1;
    }
    else {
        cout << n;    
    }
	return 0;
}