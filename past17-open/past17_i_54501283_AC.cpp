/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54501283
 * Submitted at: 2024-06-13 18:42:32
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_i
 * Result: AC
 * Execution Time: 4181 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    ll ans = n;
    auto f = [&]() -> void {
        map<string, ll> mp;
        rep(i, n) {
            ans += mp[s[i]];
            set<string> st;
            reps(j, 1, (1LL << s[i].size())) {
                string t = "";
                rep(k, s[i].size()) if(j & (1LL << k)) t += s[i][k];
                st.insert(t);
            }
            for(auto x : st) mp[x]++;
        }
    };
    f();
    reverse(s.begin(), s.end());
    f();
    cout << ans << endl;
    
    return 0;
}