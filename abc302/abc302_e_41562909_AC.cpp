/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc302/submissions/41562909
 * Submitted at: 2023-05-20 21:49:24
 * Problem URL: https://atcoder.jp/contests/abc302/tasks/abc302_e
 * Result: AC
 * Execution Time: 442 ms
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
    
    ll n,q; input(n,q);
    vector<ll> cnt(n,0);
    set<P> edge;
    ll ans = n;
    while(q--){
        ll t; input(t);
        if(t == 1){
            ll u,v; input(u,v);
            u--; v--;
            edge.insert(P(u,v));
            edge.insert(P(v,u));
            if(cnt[u] == 0)ans--;
            if(cnt[v] == 0)ans--;
            cnt[u]++;
            cnt[v]++;
        }
        else{
            ll v; input(v);
            v--;
            while(true){
                auto itr = edge.lower_bound(P(v,-1));
                if(itr == edge.end() || (*itr).first != v)break;

                auto [x,y] = *itr;
                cnt[x]--;
                cnt[y]--;
                if(cnt[x] == 0)ans++;
                if(cnt[y] == 0)ans++;
                edge.erase(itr);
                auto i2 = edge.lower_bound(P(y,x));
                edge.erase(i2);
            }
        }
        print(ans);
    }
    
    return 0;
}