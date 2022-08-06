/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc183/submissions/33792095
 * Submitted at: 2022-08-06 11:51:23
 * Problem URL: https://atcoder.jp/contests/abc183/tasks/abc183_c
 * Result: AC
 * Execution Time: 10 ms
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
    
    ll n,k; cin >> n >> k;
    vector t(n,vector<int>(n));
    rep(i,n)rep(j,n)cin >> t[i][j];
    vector<int> p(n-1);
    iota(p.begin(),p.end(),0);

    ll ans = 0;
    do{
        ll score = t[p[0]+1][0] + t[0][p.back()+1];
        rep(i,n-2)score += t[p[i+1]+1][p[i]+1];
        if(score == k)ans++;
    }while(next_permutation(p.begin(),p.end()));

    cout << ans << endl;
    
    return 0;
}