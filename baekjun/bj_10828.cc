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
vector<int> stack;
int main() {
    int N;

    cin >> N;

    string cmd;
    int tmpVal;
    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> tmpVal;
            stack.push_back(tmpVal);
        }
        else if (cmd == "pop") {
            if(stack.size() >= 1) {
                cout << stack.back() << endl;
                stack.pop_back();
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if (cmd  == "size") {
            cout << stack.size() << endl;
        }
        else if (cmd == "empty") {
            cout << ((stack.empty()) ? 1 : 0) << endl;
        }
        else {
            if (stack.size() >= 1) 
                cout << stack.back() << endl;
            else
                cout << "-1" << endl;
        }

    }

    return 0;
}