/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54499469
 * Submitted at: 2024-06-13 17:33:33
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_e
 * Result: AC
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<char, ll>;
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
    
    string s; cin >> s;
    char pre = s[0];
    ll cnt = 0;
    vector<P> ans;
    rep(i,s.size()) {
        if(pre == s[i]) {
            cnt++;
        }
        else {
            ans.emplace_back(pre, cnt);
            pre = s[i];
            cnt = 1;
        }
    }
    ans.emplace_back(s[s.size()-1], cnt);
    for(auto [c, n] : ans) cout << c << " " << n << " ";
    cout << endl;
    
    return 0;
}