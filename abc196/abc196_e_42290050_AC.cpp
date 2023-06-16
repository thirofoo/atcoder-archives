/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc196/submissions/42290050
 * Submitted at: 2023-06-16 16:00:32
 * Problem URL: https://atcoder.jp/contests/abc196/tasks/abc196_e
 * Result: AC
 * Execution Time: 71 ms
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
    
    // 解説AC
    // t = 2,3 → 範囲を狭めるクエリ
    // t = 1   → 値を変化させるクエリ
    // → 範囲と値の変位を保持
    // → 値が最終範囲を満たしていればその値、overで上限,belowで下限 !!

    ll n; input(n);
    ll high = 1e16, low = -1e16, ab = 0;
    rep(i,n){
        ll a,t; input(a,t);
        if(t == 1){
            ab += a;
            high += a;
            low += a;
        }
        else if(t == 2){
            high = max(high,a);
            low  = max(low,a);
        }
        else{
            high = min(high,a);
            low  = min(low,a);
        }
    }
    ll q; input(q);
    while(q--){
        ll x; input(x);
        x += ab; // 全ての変位を反映
        x = min(high,x);
        x = max(low ,x);
        print(x);
    }
    
    return 0;
}

