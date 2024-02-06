/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/50057857
 * Submitted at: 2024-02-06 18:38:13
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_e
 * Result: WA
 * Execution Time: 125 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(n), c(m), d(m);
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];
    rep(i,0,m) cin >> c[i];
    rep(i,0,m) cin >> d[i];
    vector<T> item;
    rep(i,0,n) item.emplace_back(T(a[i],b[i],0));
    rep(i,0,m) item.emplace_back(T(c[i],d[i],1));
    sort(item.begin(), item.end(), [](T t1, T t2){
        auto &&[a1, b1, s1] = t1;
        auto &&[a2, b2, s2] = t2;
        if( a1 != a2 ) return a1 > a2;
        if( b1 != b2 ) return b1 > b2;
        return s1 > s2;
    });
    set<ll> yoko;
    rep(i,0,item.size()) {
        auto [a,b,t] = item[i];
        if( t == 0 ) {
            auto itr = yoko.lower_bound(b);
            if( itr == yoko.end() ) return cout << "No" << endl, 0;
            yoko.erase(itr);
        }
        else yoko.insert(b);
    }
    cout << "Yes" << endl;
    
    return 0;
}