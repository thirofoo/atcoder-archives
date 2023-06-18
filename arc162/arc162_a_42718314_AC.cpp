/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc162/submissions/42718314
 * Submitted at: 2023-06-18 21:08:58
 * Problem URL: https://atcoder.jp/contests/arc162/tasks/arc162_a
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll t; input(t);
    while(t--){
        ll n; input(n);
        vector<P> p;
        rep(i,n){
            ll tmp; input(tmp);
            p.push_back(P(tmp,i+1));
        }
        sort(p.begin(),p.end());
        ll ans = 0, now = 0;
        rep(i,n){
            auto [ato,mae] = p[i];
            if(mae >= now){
                now = mae;
                ans++;
            }
        }
        print(ans);
    }
    
    return 0;
}