#include <iostream>                                                              
#include <string>                                                                
#include <string.h>                                                              
#include <vector>    
#include <queue>
#include <deque>
using namespace std;
deque<int> card;

int calLastNum() 
{
    int popVal;
    bool trashFlag = true;
    while (card.size() > 1) {
        if (trashFlag) {
            card.pop_back();
            trashFlag = false;
        }
        else {
            popVal = card.back();
            card.pop_back();
            card.push_front(popVal);
            trashFlag = true;
        }
    }
    return card.back();
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        card.push_front(i);
    }

    cout << calLastNum();


    return 0;
}