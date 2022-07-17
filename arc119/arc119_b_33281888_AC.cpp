/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc119/submissions/33281888
 * Submitted at: 2022-07-17 12:35:38
 * Problem URL: https://atcoder.jp/contests/arc119/tasks/arc119_b
 * Result: AC
 * Execution Time: 20 ms
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
    
    ll n; string s,t; cin >> n >> s >> t;
    vector<int> a,b;
    rep(i,n){
        if(s[i] == '0')a.push_back(i);
        if(t[i] == '0')b.push_back(i);
    }
    if(a.size() != b.size())return cout << -1 << endl,0;
    ll ans = 0;
    rep(i,a.size()){
        if(a[i] != b[i])ans++;
    }
    cout << ans << endl;
    
    return 0;
}