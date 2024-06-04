/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc350/submissions/54217482
 * Submitted at: 2024-06-04 12:58:30
 * Problem URL: https://atcoder.jp/contests/abc350/tasks/abc350_f
 * Result: AC
 * Execution Time: 21 ms
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
        if(s[i] == '(') {
            st.push(i);
        }
        else if(s[i] == ')') {
            ll l = st.top(); st.pop();
            pair[l] = i;
            pair[i] = l;
        }
    }

    // 大小判定
    vector<ll> imos(n, 0);
    rep(i, n) {
        if( s[i] != '(' ) continue;
        imos[i]++, imos[pair[i]+1]--;
    }
    rep(i, n-1) imos[i+1] += imos[i];

    // 再起関数が無難
    auto f = [&](auto self, ll l, ll r, bool rev) -> void {
        if(rev) {
            for(ll i=r; i>=l; i--) {
                if( s[i] == ')' ) {
                    self(self, pair[i]+1, i-1, !rev);
                    i = pair[i];
                }
                else {
                    char ch = s[i];
                    if(imos[i]%2 == 1) {
                        ch = (isupper(ch) ? tolower(ch) : toupper(ch));
                    }
                    cout << ch;
                }
            }
        }
        else {
            for(ll i=l; i<=r; i++) {
                if( s[i] == '(' ) {
                    self(self, i+1, pair[i]-1, !rev);
                    i = pair[i];
                }
                else {
                    char ch = s[i];
                    if(imos[i]%2 == 1) {
                        ch = (isupper(ch) ? tolower(ch) : toupper(ch));
                    }
                    cout << ch;
                }
            }
        }
    };
    f(f, 0, n-1, false);
    cout << endl;
    
    return 0;
}