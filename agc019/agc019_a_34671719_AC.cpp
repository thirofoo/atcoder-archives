/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc019/submissions/34671719
 * Submitted at: 2022-09-07 18:35:20
 * Problem URL: https://atcoder.jp/contests/agc019/tasks/agc019_a
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
    
    ll q,h,s,d,n; input(q,h,s,d,n);
    q *= 4; h *= 2;
    ll ans = 0;
    if(d < q*2 && d < h*2 && d < s*2){
        ans += (n/2)*d;
        n %= 2;
    }
    if(q > h)swap(q,h);
    if(q > s)swap(q,s);
    ans += n*q;
    print(ans);
    
    return 0;
}