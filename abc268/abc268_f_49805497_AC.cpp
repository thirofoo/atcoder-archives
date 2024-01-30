/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc268/submissions/49805497
 * Submitted at: 2024-01-30 14:59:25
 * Problem URL: https://atcoder.jp/contests/abc268/tasks/abc268_f
 * Result: AC
 * Execution Time: 20 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<string> s(n);
    vector<T> info;
    rep(i,n) {
        cin >> s[i];
        ll num = 0, cnt = 0, score = 0;
        rep(j,s[i].size()) {
            if( s[i][j] == 'X' ) cnt++;
            else {
                num += (s[i][j]-'0');
                score += cnt * (s[i][j]-'0');
            }
        }
        info.emplace_back(T(cnt,num,score));
    }
    sort(info.begin(), info.end(), [&](T e1, T e2){
        auto &&[c1, n1, s1] = e1;
        auto &&[c2, n2, s2] = e2;
        return c1*n1+(c1+c2)*n2 > c2*n2+(c1+c2)*n1;
    });
    ll ans = 0, cnt = 0;
    rep(i,n) {
        auto &&[c, num, score] = info[i];
        ans += score + cnt*num;
        cnt += c;
    }
    cout << ans << endl;
    
    return 0;
}