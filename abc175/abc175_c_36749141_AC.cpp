/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc175/submissions/36749141
 * Submitted at: 2022-11-24 12:40:34
 * Problem URL: https://atcoder.jp/contests/abc175/tasks/abc175_c
 * Result: AC
 * Execution Time: 6 ms
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
    
    ll x,k,d; input(x,k,d);
    x = abs(x);
    ll cnt = x/d,c1 = x%d,c2 = abs((x%d)-d);
    if(c1 > c2)cnt++;
    // print(cnt);

    if(k <= cnt)print(x-d*k);
    else {
        if((k-cnt)%2 == 0)print(min(c1,c2));
        else print(max(c1,c2));
    }
    
    return 0;
}