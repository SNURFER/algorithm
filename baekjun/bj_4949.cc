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
vector<char> balChecker;

void calBalance(string input) 
{
    //initialize
    balChecker.clear();

    for (int i = 0; i < input.size(); i++) {
        if(input[i] == '(') {
            balChecker.push_back('(');
        }
        else if (input[i] == ')') {
            if (balChecker.back() == '(') {
                balChecker.pop_back();
            }
            else {
                cout << "no" << endl;
                return;
            }
        }
        else if (input[i] == '{') {
            balChecker.push_back('{');
        }
        else if (input[i] == '}') {
            if (balChecker.back() == '{') {
                balChecker.pop_back();
            }
            else {
                cout << "no" << endl;
                return;
            }
        }
        else if (input[i] == '[') {
            balChecker.push_back('[');
        }
        else if (input[i] == ']') {
            if (balChecker.back() == '[') {
                balChecker.pop_back();
            }
            else {
                cout << "no" << endl;
                return;
            }
        }

    }

    if (balChecker.size() == 0) {
        cout << "yes" << endl;
        return;
    }
    cout << "no" << endl;
}

int main() {

    string tmpString = "";
    while(true) {
        getline(cin, tmpString);
        if(tmpString == ".")
            break;
        calBalance(tmpString);

        tmpString.clear();
    }

    return 0;
}