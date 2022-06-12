/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc255/submissions/32429534
 * Submitted at: 2022-06-12 12:12:20
 * Problem URL: https://atcoder.jp/contests/abc255/tasks/abc255_e
 * Result: AC
 * Execution Time: 757 ms
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
    
    int n,m; cin >> n >> m;
    vector<int> s(n-1),x(m);
    rep(i,n-1)cin >> s[i];
    rep(i,m)cin >> x[i];

    vector<ll> cnt(n,0);
    for(int i=2;i<n;i++)cnt[i] += cnt[i-2]+s[i-1]-s[i-2];

    //初項がkeyの時のluckyの数value。
    map<ll,int> cand;

    //初項を探索してもキリがない
    //→ i項目がluckyになるような時の初項を逆算してカウント。
    rep(i,n){
        rep(j,m){
            //xはどれも異なるから初項被りは考慮しなくてok
            if(i%2 == 0)cand[x[j]-cnt[i]]++;
            else cand[s[0]-(x[j]-cnt[i])]++;
        }
    }
    int ans = 0;
    for(auto k:cand)ans = max(ans,k.second);
    cout << ans << endl;

    return 0;
}