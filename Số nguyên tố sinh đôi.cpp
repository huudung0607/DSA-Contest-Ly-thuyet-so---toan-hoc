#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int prime[1000005];

void sieve(int l, int r){
    for(int i = 0; i <= r - l; i++){
        prime[i] = 1;
    }
    for(int i = 2; i <= sqrt(r); i++){
        for(int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i){
            prime[j - l] = 0;
        }
    }
    int ans = 0;
    for(int i = max(l, 2); i <= r - 2; i++){
        if(prime[i - l] && prime[i + 2 - l]) ++ans;
    }
    cout << ans << endl;
}

int main(){
    int l, r; cin >> l >> r;
    sieve(l, r);
}
