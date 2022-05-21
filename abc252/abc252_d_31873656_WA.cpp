/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/31873656
 * Submitted at: 2022-05-21 22:33:21
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_d
 * Result: WA
 * Execution Time: 30 ms
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
    
    ll n; cin >> n;
    vector<int> cnt(200010,0),vary;
    rep(i,n){
        int a; cin >> a;
        cnt[a]++;
    }
    rep(i,200010)if(cnt[i] >= 2)vary.push_back(cnt[i]);
    sort(vary.begin(),vary.end());

    ll ans = n*(n-1)*(n-2)/6;
    for(auto k:vary){
        ans -= (k*(k-1)/2) * (n-k);
        if(k >= 3) ans -= (k*(k-1)*(k-2)/6);
    }

    cout << ans << endl;

    return 0;
}