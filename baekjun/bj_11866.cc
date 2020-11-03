#include <iostream>                                                              
#include <string>                                                                
#include <string.h>                                                              
#include <vector>    
#include <queue>
#include <deque>
using namespace std;
queue<int> yosePuss;

int main() {
    int N, K, tmp;
    cin  >> N >> K;

    for (int i = 1; i <= N; i++) {
        yosePuss.push(i);
    }

    cout << "<";
    while (yosePuss.size() > 1) {
        for(int i = 1; i <= K; i++) {
            tmp = yosePuss.front();
            yosePuss.pop();
            if (i != K) {
                yosePuss.push(tmp);
            }
            else {
                cout << tmp << ", ";
            }
        }
    }
    cout << yosePuss.front() << ">";

    return 0;
}