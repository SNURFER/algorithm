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
    int N, tmp;
    int ans = 0;
    vector<int> stack;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if (tmp == 0)
            stack.pop_back();
        else
            stack.push_back(tmp);
    }
    for (int i = 0; i < stack.size(); i++) {
        ans += stack[i];
    }
    cout << ans;
    return 0;
}