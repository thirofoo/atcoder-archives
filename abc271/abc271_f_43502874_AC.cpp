/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc271/submissions/43502874
 * Submitted at: 2023-07-12 16:02:53
 * Problem URL: https://atcoder.jp/contests/abc271/tasks/abc271_f
 * Result: AC
 * Execution Time: 144 ms
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
    
    // 解説AC : 半分全列挙
    // 対角線上はどの経路でも必ず1回のみ通る → 対角線経路で2分して半分全列挙
    ll n; input(n);
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n) input(a[i][j]);

    vector<vector<ll>> cand1(n), cand2(n);
    rep(i, (1LL << n-1)){
        ll cnt = 0, now = 0;
        rep(j, n-1){
            // cnt : 下に行く回数
            now ^= a[cnt][j-cnt];
            cnt += ( (i & (1LL << j)) > 0 );
        }
        cand1[cnt].push_back(now);
    }
    rep(i, (1LL << n-1)){
        ll cnt = 0, now = 0;
        rep(j, n-1){
            // cnt : 上に行く回数
            now ^= a[n-1-cnt][n-1-(j-cnt)];
            cnt += ( (i & (1LL << j)) > 0 );
        }
        cand2[n-1-cnt].push_back(now);
    }
    rep(i,n) sort(cand1[i].begin(), cand1[i].end());
    rep(i,n) sort(cand2[i].begin(), cand2[i].end());

    ll ans = 0;
    rep(i,n){
        // start ~ 対角線
        for(auto ele:cand1[i]){
            auto itr1 = lower_bound(cand2[i].begin(), cand2[i].end(), ele^a[i][n-1-i]);
            auto itr2 = upper_bound(cand2[i].begin(), cand2[i].end(), ele^a[i][n-1-i]);
            ans += itr2 - itr1;
        }
    }
    print( ans );
    
    return 0;
}