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
void executor(int n1, int n2) {

    if (n1 % n2 == 0)
    {
        cout << "multiple" << endl;
    }
    else if (n2 % n1 == 0)
    {
        cout << "factor" << endl;
    }
    else
    {
        cout << "neither" << endl;
    }
}

int main(){
    int N1, N2;
    while (true)
    {
        cin >> N1 >> N2;
        if (N1 == 0 && N2 == 0) break;

        executor(N1, N2);
    }

    return 0;
}