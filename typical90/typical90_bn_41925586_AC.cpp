/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41925586
 * Submitted at: 2023-06-03 15:14:32
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bn
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n; input(n);
    vector<P> lr;
    rep(i,n){
        ll l,r; input(l,r);
        lr.push_back(P(l,r));
    }
    // 転倒数の期待値 = 列のペアでの転倒数の期待値の総和 (線形性っぽい？)
    ld ans = 0;
    rep(i,n){
        for(ll j=i+1;j<n;j++){
            auto &&[l1,r1] = lr[i];
            auto &&[l2,r2] = lr[j];
            ld total = (r1-l1+1) * (r2-l2+1);
            ld ok = 0;
            for(ll k=l2;k<=r2;k++){
                ok += min( max(r1-k,0LL), r1-l1+1 );
            }
            ans += ok/total;
        }
    }
    print(ans);
    
    return 0;
}