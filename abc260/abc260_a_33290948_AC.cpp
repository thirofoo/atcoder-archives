/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc260/submissions/33290948
 * Submitted at: 2022-07-17 21:01:18
 * Problem URL: https://atcoder.jp/contests/abc260/tasks/abc260_a
 * Result: AC
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    map<char,int> cnt;
    rep(i,3)cnt[s[i]]++;
    rep(i,3)if(cnt[s[i]] == 1)return cout << s[i] << endl,0;
    cout << -1 << endl;
    
    return 0;
}