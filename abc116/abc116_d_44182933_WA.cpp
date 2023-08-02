/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc116/submissions/44182933
 * Submitted at: 2023-08-02 18:58:41
 * Problem URL: https://atcoder.jp/contests/abc116/tasks/abc116_d
 * Result: WA
 * Execution Time: 77 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC 制限無し満足度貪欲を初期値として種類数を増やしいく
    // 制限を書けないで貪欲をすると...
    // 満足度は全パターンの中で必然的にmax
    // → 種類数を増やす意味が無い
    // → 種類数を増やして行く方向で全探索

    // 種類数全探索は思いつくが初期値が思いつかず、種類の増やし方が O(N) となって死亡
    // point : 一方を全探索する時、もう一方は常に最大となるような選び方を考える

    ll n,k; cin >> n >> k;
    priority_queue<P> no_used;
    priority_queue<P,vector<P>,greater<P>> used;
    rep(i,n) {
        ll t, d; cin >> t >> d;
        no_used.push(P(d,t));
    }
    ll now = 0, ans = 0;
    set<ll> st;
    rep(i,k) {
        used.push(no_used.top());
        auto [d, t] = no_used.top(); no_used.pop();
        st.insert(t);
        now += d;
    }
    ans = now + st.size()*st.size();
    while( !no_used.empty() ) {
        auto [d, t] = no_used.top(); no_used.pop();
        if( st.count(t) ) continue;
        st.insert(t);
        now -= used.top().first;
        now += d;
        ans = max(ans,now + (ll)(st.size()*st.size()));
    }
    cout << ans << endl;
    
    return 0;
}