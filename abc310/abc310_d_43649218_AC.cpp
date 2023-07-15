/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc310/submissions/43649218
 * Submitted at: 2023-07-15 23:58:42
 * Problem URL: https://atcoder.jp/contests/abc310/tasks/abc310_d
 * Result: AC
 * Execution Time: 8 ms
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
    vector<vector<bool>> ng(n,vector<bool>(n,false));
    rep(i,m){
        ll a,b; input(a,b);
        a--; b--;
        ng[a][b] = true;
        ng[b][a] = true;
    }

    ll ans = 0;
    auto f = [&](auto self, vector<vector<ll>> &team, ll now){
        if( now == n ){
            bool flag = true;
            rep(i,t) flag &= (!team[i].empty());
            ans += flag;
            return;
        }
        rep(i,t){
            bool flag = false;
            for(ll j=0;j<team[i].size();j++){
                if( ng[now][team[i][j]] ){
                    flag = true;
                    break;
                }
            }
            if( flag )continue;

            team[i].push_back(now);
            self(self,team,now+1);
            team[i].pop_back();

            if( team[i].empty() ) break;
        }
    };

    vector<vector<ll>> team(t,vector<ll>{});
    f(f,team,0);
    print( ans );
    
    return 0;
}