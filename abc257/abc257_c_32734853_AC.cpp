/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/32734853
 * Submitted at: 2022-06-25 21:56:41
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_c
 * Result: AC
 * Execution Time: 256 ms
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
    
    int n; string s; cin >> n >> s;
    vector<int> w(n),mi(n+1,0),ma(n+1,0);
    set<int> we;
    int ad_cnt = 0;
    rep(i,n){
        if(s[i] == '1')ad_cnt++;
        cin >> w[i];
        we.insert(w[i]);
    }
    map<int,P> cnt;
    rep(i,n){
        if(s[i] == '0')cnt[w[i]].first++;
        else cnt[w[i]].second++;
    }

    int idx = 1;
    ma[0] = ad_cnt;
    for(auto l:we){
        ma[idx] = ma[idx-1] - cnt[l].second;
        mi[idx] = mi[idx-1] + cnt[l].first;
        idx++;
    }
    
    int ans = 0;
    rep(i,n+1)ans = max(ans,ma[i]+mi[i]);
    cout << ans << endl;
    

    return 0;
}