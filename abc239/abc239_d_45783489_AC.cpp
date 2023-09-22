/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc239/submissions/45783489
 * Submitted at: 2023-09-22 09:17:56
 * Problem URL: https://atcoder.jp/contests/abc239/tasks/abc239_d
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<bool> flags;
void eratosthenes(ll n){
    flags.assign(n,true);
    flags[0] = false; flags[1] = false;
    const ll sqrt_n = ceil(sqrt(n)+0.1);
    for(ll i = 2; i < sqrt_n; i++){
        if(!flags[i])continue;
        for(ll j = i*i; j < n; j += i){
            flags[j] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b, c, d; cin >> a >> b >> c >> d;
    eratosthenes(1000);
    bool f = false;
    for(ll i=a;i<=b;i++) {
        bool ff = true;
        for(ll j=c;j<=d;j++) {
            ff &= !flags[i+j];
        }
        if( ff ) {
            f = true;
            break;
        }
    }
    cout << (f ? "Takahashi" : "Aoki") << endl;
    
    return 0;
}