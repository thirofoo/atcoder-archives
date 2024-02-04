/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc171/submissions/50010840
 * Submitted at: 2024-02-04 22:05:28
 * Problem URL: https://atcoder.jp/contests/arc171/tasks/arc171_b
 * Result: WA
 * Execution Time: 43 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n+1);
    rep(i,n) cin >> a[i+1];
    // グラフっぽくとらえられそう…？
    //  ~~ 固定マスは求められて、それ以外は制約が求まるので数え上げ出来そう…？ ~~
    // 1. まず固定マスを求める
    vector<ll> fixed(n+1,0), idx(n+1,0);
    iota(fixed.begin(),fixed.end(),0);
    iota(idx.begin(),idx.end(),0);
    set<ll> st; // 使った数字を管理
    for(ll i=n; i>0; i--) {
        if( a[i] < i ) return cout << 0 << endl, 0;
        else if( a[i] == i ) continue;
        st.insert(idx[a[i]]);
        fixed[i] = idx[a[i]];
        idx[a[i]] = i;
    }
    // 2. 使ってない数字を使っていない場所に入れる
    // ※ ただし入れる場所の index 以下の値しか入れられない
    mint ans = 1;
    for(ll i=1; i<=n-st.size(); i++) ans *= min(n-(ll)st.size()-1,i);
    cout << ans.val() << endl;
    
    return 0;
}