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
    string numberString;
    int sum = 0;
    cin >> N;
    cin >> numberString;
    for ( std::string::iterator it=numberString.begin(); it!=numberString.end(); ++it){
        sum += (int)(*it) - (int)'0';        
    }
    cout << sum;
	return 0;
}