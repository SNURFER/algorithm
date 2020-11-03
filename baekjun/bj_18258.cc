#include <iostream>                                                              
#include <algorithm>                                                             
#include <map>                                                                   
#include <string>                                                                
#include <math.h>                                                                
#include <string.h>                                                              
#include <stdlib.h> 
#include <iomanip>                                                        
#include <vector>    
#include <queue>
using namespace std;
queue<int> makeQueue;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;

    cin >> N;

    string cmd;
    int tmpVal;
    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> tmpVal;
            makeQueue.push(tmpVal);
        }
        else if (cmd == "pop") {
            if(makeQueue.size() >= 1) {
                cout << makeQueue.front() << '\n';
                makeQueue.pop();
            }
            else {
                cout << "-1" << '\n';
            }
        }
        else if (cmd  == "size") {
            cout << makeQueue.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << ((makeQueue.empty()) ? 1 : 0) << '\n';
        }
        else if (cmd == "front") {
            if (makeQueue.size() >= 1)
                cout << makeQueue.front() << '\n';
            else
                cout << "-1" << '\n';
        }
        else {
            if (makeQueue.size() >= 1) 
                cout << makeQueue.back() << '\n';
            else
                cout << "-1" << '\n';
        }
    }

    return 0;
}