/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc255/submissions/32409796
 * Submitted at: 2022-06-11 22:26:53
 * Problem URL: https://atcoder.jp/contests/abc255/tasks/abc255_e
 * Result: TLE
 * Execution Time: 4410 ms
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
    vector<int> s(n-1);
    rep(i,n-1)cin >> s[i];
    set<int> x;
    rep(i,m){
        int tmp; cin >> tmp;
        x.insert(tmp);
    }

    int ans = 0;
    map<P,int> memo;
    rep(i,n){
        for(auto j:x){
            if(memo[P(i,j)])continue;
            int cand = 1,now = j;
            for(int k=i-1;k>=0;k--){
                now = s[k]-now;
                if(x.count(now))cand++;
            }
            now = j;
            for(int k=i+1;k<n;k++){
                now += s[k];
                if(x.count(now))cand++;
            }
            ans = max(ans,cand);
            memo[P(i,j)] = cand;
        }
    }
    cout << ans << endl;

    return 0;
}