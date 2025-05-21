#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int c2 = 0, c5 = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        while(x % 2 == 0){
            ++c2; x /= 2;
        }
        while(x % 5 == 0){
            ++c5; x /= 5;
        }
    }
    cout << min(c2, c5) << endl;
}
