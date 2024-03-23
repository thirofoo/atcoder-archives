/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc346/submissions/51600676
 * Submitted at: 2024-03-23 22:22:47
 * Problem URL: https://atcoder.jp/contests/abc346/tasks/abc346_f
 * Result: WA
 * Execution Time: 564 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    string s, t; cin >> s >> t;
    vector<vector<ll>> idx(26);
    rep(i,s.size()) idx[s[i]-'a'].emplace_back(i);
    rep(i,t.size()) {
        if( idx[t[i]-'a'].empty() ) {
            cout << 0 << endl;
            return 0;
        }
    }

    // g(T,k) の文字が変わる部分が求まれば勝ち
    ll left = 0, right = 1e17 * 5;
    while( right - left > 1 ) {
        ll mid = (left + right) / 2;
        // mid 個 S を繋げた文字列上で g(T,k) が部分列にあるか
        ll s_num = 1, now = 0;
        rep(i,t.size()) {
            // t[i] が mid 個出現するまでに何回 S を使ってどこの idx にいるか
            ll next_idx = lower_bound(idx[t[i]-'a'].begin(), idx[t[i]-'a'].end(), now) - idx[t[i]-'a'].begin();
            ll after_num = idx[t[i]-'a'].size() - next_idx;
            if( mid <= after_num ) {
                now = idx[t[i]-'a'][next_idx+mid-1] + 1;
                if( now == s.size() ) {
                    s_num++;
                    now = 0;
                }
            }
            else {
                s_num++;
                now = 0;
                ll rest = mid - after_num;
                // 周期性を用いる
                s_num += (rest-1) / idx[t[i]-'a'].size();
                now = idx[t[i]-'a'][(rest-1) % idx[t[i]-'a'].size()] + 1;
                if( now == s.size() ) {
                    s_num++;
                    now = 0;
                }
            }
        }
        // cerr << s_num << " " << now << "\n";
        // cerr << "mid: " << mid << "\n\n";
        if( s_num <= n || (s_num == n+1 && now == 0) ) left = mid;
        else right = mid;
    }
    cout << left << endl;
    
    return 0;
}