/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc171/submissions/50016959
 * Submitted at: 2024-02-04 22:59:55
 * Problem URL: https://atcoder.jp/contests/arc171/tasks/arc171_b
 * Result: WA
 * Execution Time: 59 ms
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
        if( idx[a[i]] == a[i] && fixed[i] != i ) return cout << 0 << endl, 0;
        st.insert(idx[a[i]]);
        fixed[i] = idx[a[i]];
        idx[a[i]] = i;
    }
    // 2. 使ってない数字を使っていない場所に入れる
    // ※ ただし入れる場所の index 以下の値しか入れられない
    // rest[i] : i番目の使ってない数字
    // p[i] : i番目の使ってない場所の index
    // rest[i] を任意に並び替えて、任意の i に対して rest[i] <= p[i] となるようにする
    vector<ll> rest;
    for(ll i=1; i<=n; i++) if( st.find(i) == st.end() ) rest.push_back(i);
    fenwick_tree<mint> fw(n+1);
    for(ll i=1; i<=n; i++) if( fixed[i] == i ) fw.add(i,1);
    // rep(i,rest.size()) cerr << rest[i] << " ";
    // cerr << endl;
    // rep(i,n+1) cerr << fixed[i] << " ";
    // cerr << endl;
    mint ans = 1, cnt = 0;
    for(ll i=rest.size()-1; i>=0; i--) {
        if( fw.sum(rest[i],n+1).val() <= cnt.val() ) return cout << 0 << endl, 0;
        ans *= fw.sum(rest[i],n+1) - cnt;
        cnt++;
    }
    cout << ans.val() << endl;
    
    return 0;
}