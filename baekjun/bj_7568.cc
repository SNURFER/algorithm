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
    int rank;
    vector<vector<int>> dc;
    cin >> N;
    dc.assign(N, vector<int>(2, -1));
    for (int i = 0; i < N; i++) {
        cin >> dc[i][0] >> dc[i][1];
    }
    for (int i = 0; i < N; i++) {
        rank = 0;
        for (int j = 0; j < N; j++) {
            if ( i == j) continue;
            if (dc[i][0] < dc[j][0] && dc[i][1] < dc[j][1]) {
                rank++;
            }
        }
        cout << rank + 1 << endl;
    }

    return 0;
}