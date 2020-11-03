#include <iostream>                                                              
using namespace std;

long long pow(long long A, long long B, long long C)
{
    if (B == 0) {
        return 1;
    }
    else  if (B % 2 == 0) {
        long long ret = pow(A, B / 2, C) % C;
        return (ret * ret) % C;
    }
    else {
        long long ret = pow(A, B / 2, C) % C;
        return (ret * ret) % C * (A % C) % C;
    }
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    cout << pow(A, B, C) % C;

    return 0;
}