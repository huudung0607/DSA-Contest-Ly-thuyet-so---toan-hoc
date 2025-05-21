#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = (int)1e5;

int prime[maxn + 1];

void sang(){
    for(int i = 0; i <= maxn; i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= sqrt(maxn); i++){
        if(prime[i]){
            for(int j = i * i; j <= maxn; j += i){
                prime[j] = 0;
            }
        }
    }
}

vector<int> nt;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    sang();
    for(int i = 0; i <= 10000; i++){
        if(prime[i]) nt.push_back(i);
    }
    vector<ll> res;
    for(int i = 0; i < nt.size(); i++){
        if(nt[i] < 30)
            res.push_back((ll)pow(nt[i], 8));
        for(int j = i + 1; j < nt.size(); j++){
            if((ll)pow(nt[i], 2) * (ll)pow(nt[j], 2) <= 1e8)
                res.push_back((ll)pow(nt[i], 2) * (ll)pow(nt[j], 2));
        }
    }
    sort(res.begin(), res.end());
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int dem = 0;
        for(ll x : res){
            if(x >= a && x <= b) ++ dem;
            else if(x > b) break;
        }
        cout << dem << endl;
    }
}
