#include <bits/stdc++.h>
using namespace std;

bool check(long long n){
    while(n % 2 == 0){
        n /= 2;
    }
    return n == 1;
}

int main(){
    long long n;
    cin >> n;
    if(check(n)) cout << "YES\n";
    else cout << "NO\n";
}
