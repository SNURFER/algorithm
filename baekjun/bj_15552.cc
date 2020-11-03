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
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, v1, v2;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> v1;
        cin >> v2;
        cout << v1 + v2 << '\n';
    }
	return 0;
}