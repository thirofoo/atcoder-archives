/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54499205
 * Submitted at: 2024-06-13 17:23:47
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_b
 * Result: WA
 * Execution Time: 1 ms
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
    vector<string> s(n);
    set<string> st;
    rep(i, n) {
        cin >> s[i];
        st.insert(s[i]);
    }
    if(st.size() > 2) cout << "Failed" << endl;
    else if(st.size() == 2) {
        if(st.count("Perfect") && st.count("Great")) cout << "Full Combo" << endl;
        else cout << "Failed" << endl;
    }
    else {
        if(st.count("Perfect")) cout << "All Perfect" << endl;
        else cout << "Failed" << endl;
    }
    
    return 0;
}