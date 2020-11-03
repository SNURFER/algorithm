#include <iostream>
#include <vector>    

using namespace std;

#define MOD 1000000007LL

vector<long long> fac;
vector<long long> inv;

/*
    페르마 소정리를 이용한 nCr 빠르게 구하기
    팩토리얼 % MOD 값을 먼저 전처리 한후
    각 팩토리얼의 modular inverse를 구함

    nCr = n!/k!(n-k)! 이므로 우리는 1 / k!(n-k)!을

    페르마 소정리에 따라 k!(n-k)!^MOD-2 으로 치환이 가능함.

*/

long long solve(long long x, long long y) {
    long long ret = 1;
    while(y > 0) {
        if(y % 2) {
            ret *= x;
            ret %= MOD;
        }
        x *= x;
        x %= MOD;
        y /= 2;
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> m >> n;

    fac.assign(4000001, 0);
    inv.assign(4000001, 0);

    fac[1] = 1;
    for(int i = 2; i <= m; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    inv[m] = solve(fac[m], MOD - 2); 

    for(int i = m - 1; i >= 1; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD; 

    long long first = fac[m] * inv[m - n] % MOD;

    if(m == n || n == 0) cout<<1;
    else cout << first * inv[n] % MOD;

    return 0;
}