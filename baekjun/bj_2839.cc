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
    cin >> N;
    
    if(N < 5){
        if(N == 3)
            cout << 1;
        else {
            cout << -1;
        }
    }
    else if(N == 7){
        cout << -1;
    }
    else {
        if(N % 5 == 0)
            cout << N / 5;
        else if(N % 5 == 1)
            cout << N / 5 + 1;
        else if(N % 5 == 2)
            cout << N / 5 + 2;
        else if(N % 5 == 3)
            cout << N / 5 + 1;
        else 
            cout << N / 5 + 2;
    }
	return 0;
}