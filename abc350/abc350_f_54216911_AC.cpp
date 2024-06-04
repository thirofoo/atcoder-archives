/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc350/submissions/54216911
 * Submitted at: 2024-06-04 12:19:11
 * Problem URL: https://atcoder.jp/contests/abc350/tasks/abc350_f
 * Result: AC
 * Execution Time: 907 ms
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
    
    string s; cin >> s;
    ll n = s.size();
    stack<ll> st;
    vector<ll> pair(n, -1);
    rep(i, n) {
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')') {
            ll l = st.top(); st.pop();
            pair[l] = i;
            pair[i] = l;
        }
    }
    // 大文字か小文字化の判定
    vector<ll> imos(n, 0);
    rep(i, n) {
        if( pair[i] == -1 ) continue;
        ll l = min(i, pair[i]);
        ll r = max(i, pair[i]);
        imos[l+1]++, imos[r]--;
    }
    imos[0] /= 2;
    rep(i, n-1) {
        imos[i+1] /= 2;
        imos[i+1] += imos[i];
        cerr << imos[i] << " ";
    }
    cerr << imos.back() << endl;

    // pair を用いて reverse 考慮操作
    vector<ll> ans;
    vector<bool> vis(n, false);
    ll rev_cnt = 0, vis_cnt = 0, now_idx = 0;
    stack<ll> back; // 巻き戻し用 stack
    while( 0 <= now_idx && now_idx < n ) {
        if( vis[now_idx] ) {
            now_idx = back.top(); back.pop();
            rev_cnt--;
        }
        else if( s[now_idx] == '(' ) {
            ll l = min(now_idx, pair[now_idx]);
            ll r = max(now_idx, pair[now_idx]);
            now_idx = r-1;
            vis[l] = vis[r] = true;
            rev_cnt++;
            vis_cnt += 2;
            back.push(r+1);
        }
        else if( s[now_idx] == ')' ) {
            ll l = min(now_idx, pair[now_idx]);
            ll r = max(now_idx, pair[now_idx]);
            now_idx = l+1;
            vis[l] = vis[r] = true;
            rev_cnt++;
            vis_cnt += 2;
            back.push(l-1);
        }
        else {
            ans.emplace_back(now_idx);
            vis[now_idx] = true;
            now_idx += (rev_cnt%2 == 0 ? 1 : -1);
            vis_cnt++;
        }
    }
    rep(i, ans.size()) {
        char ch = s[ans[i]];
        if( imos[ans[i]]%2 == 1 ) {
            ch = (isupper(ch) ? ch-'A'+'a' : ch-'a'+'A');
        }
        cout << ch;
    }
    cout << endl;
    
    return 0;
}