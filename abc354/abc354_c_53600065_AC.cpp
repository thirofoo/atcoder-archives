/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc354/submissions/53600065
 * Submitted at: 2024-05-18 21:16:42
 * Problem URL: https://atcoder.jp/contests/abc354/tasks/abc354_c
 * Result: AC
 * Execution Time: 96 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<T> card;
    rep(i,n) {
        ll a, c; cin >> a >> c;
        card.push_back({a,c,i});
    }
    sort(card.begin(), card.end(), [](T a, T b) {
        auto [aa, ac, ai] = a;
        auto [ba, bc, bi] = b;
        if( aa != ba ) return aa > ba;
        else return ac < bc;
    });

    vector<ll> ans;
    set<ll> st;
    auto [fa, fc, fi] = card[0];
    ans.emplace_back(fi+1);
    st.insert(fc);
    
    reps(i,1,n) {
        auto [a, c, idx] = card[i];
        auto itr = st.lower_bound(c);
        if( itr == st.begin() ) {
            st.insert(c);
            ans.push_back(idx+1);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    rep(i,ans.size()) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}