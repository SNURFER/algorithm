#include <iostream>                                                              
#include <string>                                                                
#include <string.h>                                                              
#include <vector>    
#include <stack>    
using namespace std;
stack<int> arrayHelper;

int main() {

    string cmd;
    int latestPushedValue, targetVal, N;
    cin >> N;
    latestPushedValue = 0;

    for (int i = 0; i < N; i++) {
        cin >> targetVal;
        while(true) {
            if (arrayHelper.size() > 0 && arrayHelper.top() == targetVal) {
                arrayHelper.pop();
                cmd += "-";
                break;
            }

            latestPushedValue++;
            arrayHelper.push(latestPushedValue);
            cmd += "+";

            if (arrayHelper.top() > targetVal) {
                cmd.clear();
                break;
            }
        }
    }

    if (cmd.size() == 0) {
        cout << "NO" << endl;
    }
    else {
        for (int i = 0; i < cmd.size(); i++) {
            cout << cmd[i] << "\n";
        }
    }
    return 0;
}