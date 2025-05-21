#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//O(NlogN) > O(NcanN)
//Những số là bội số của 1 số nguyên tố => ko phải là snt
// p[i] : Tổng các ước của số i

int p[1000005];
int F[1000005];

//F[i] : từ 0 tới i có bao nhiêu số ưu thế
//F[r] - F[l - 1]

void sang(){
    for(int i = 1; i <= 1000000; i++){
        for(int j = i; j <= 1000000; j += i){
            p[j] += i;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    sang();
    int dem = 0;
    for(int i = 1; i <= 1000000; i++){
        if(p[i] - i > i) ++dem;
        F[i] = dem;
    }
    //p[i] - i > i => ok
    int t; cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        cout << F[r] - F[l - 1] << endl; // O(1)
    }
}
