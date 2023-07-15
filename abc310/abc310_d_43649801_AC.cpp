/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc310/submissions/43649801
 * Submitted at: 2023-07-16 00:17:13
 * Problem URL: https://atcoder.jp/contests/abc310/tasks/abc310_d
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
    
    ll n,t,m; input(n,t,m);
    vector<ll> ng(n,0);
    rep(i,m){
        ll a,b; input(a,b);
        a--; b--;
        ng[a] |= (1LL << b);
        ng[b] |= (1LL << a);
    }

    ll ans = 0;
    vector<ll> team(t,0);
    auto f = [&](auto self, ll now){
        if( now == n ){
            bool flag = true;
            rep(i,t) flag &= (team[i] > 0);
            if( flag )ans++;
            return;
        }
        rep(i,t){
            if( ng[now] & team[i] )continue;
            team[i] ^= (1LL << now);
            self(self, now+1);
            team[i] ^= (1LL << now);
            if( team[i] == 0 ) break;
        }
    };

    f(f, 0);
    print( ans );
    
    return 0;
}