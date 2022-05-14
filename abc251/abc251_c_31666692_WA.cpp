/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/31666692
 * Submitted at: 2022-05-14 21:15:15
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_c
 * Result: WA
 * Execution Time: 87 ms
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
    
    int n,ans = 0,now = 0; cin >> n;
    map<string,int> poem;
    rep(i,n){
        string s; int t; cin >> s >> t;
        if(poem[s] || now >= t)continue;
        poem[s]++;
        now = t;
        ans = i+1;
    }
    cout << ans << endl;
    return 0;
}