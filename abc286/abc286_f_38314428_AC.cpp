/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc286/submissions/38314428
 * Submitted at: 2023-01-25 15:30:01
 * Problem URL: https://atcoder.jp/contests/abc286/tasks/abc286_f
 * Result: AC
 * Execution Time: 17 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll m = 108;
    vector<ll> p = {4,9,5,7,11,13,17,19,23};
    vector<ll> a(m);
    ll now = 0;
    for(auto ele:p){
        rep(i,ele)a[i+now] = (i+1)%ele+now+1;
        now += ele;
    }
    print(m);
    cout << flush;
    rep(i,m)cout << a[i] << " ";
    print();
    cout << flush;

    vector<ll> b(m),c(9);
    rep(i,m)input(b[i]);
    now = 0;
    rep(i,9){
        c[i] = mod(b[i+now]-a[i+now]+1,p[i]);
        now += p[i];
    }

    print(crt(c,p).first);
    cout << flush;
    
    return 0;
}