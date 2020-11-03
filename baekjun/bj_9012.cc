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
string ps;

void findVPS(string ps) {
    int psChecker = 0;
    for (int i = 0; i < ps.size(); i++) {
        if (ps[i] == '(')
            psChecker++;
        else 
            psChecker--;

        if (psChecker < 0) {
            cout << "NO" << endl;
            return;
        } 

    }
    if (psChecker == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> ps;
        findVPS(ps);
        ps.clear();
    }
    return 0;
}