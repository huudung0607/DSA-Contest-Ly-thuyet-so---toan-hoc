#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<int, int> mp;
int n, a[10005];
int mod = 1e9 + 7;

ll powMod(ll a, ll b, ll c){
    ll res = 1;
    while(b){
        if(b % 2){
            res *= a; res %= c;
        }
        a *= a;
        a %= c;
        b /= 2;
    }
    return res;
}

void pt(int n){
    for(int i = 2; i <= sqrt(n); i++){
        while(n % i == 0){
            mp[i]++;
            n /= i;
        }
    }
    if(n > 1) mp[n]++;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    int countZero = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) countZero = 1;
    }
    if(countZero == 1){
        cout << "28tech 0" << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            pt(a[i]);
        }
        ll res = 1;
        for(auto it : mp){
            if(it.second % 2 == 1){
                cout << "29tech\n";
                return 0;
            }
            else{
                res *= powMod(it.first, it.second / 2, mod);
                res %= mod;
            }
        }
        cout << "28tech " << res << endl;
    }
}
