/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/32897052
 * Submitted at: 2022-07-02 21:14:31
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_b
 * Result: WA
 * Execution Time: 7 ms
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

vector<int> dx = {-1,-1,-1,0,1,1,1,0};
vector<int> dy = {-1,0,1,1,1,0,-1,-1};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,sx = 0,sy = 0; cin >> n;
    vector<string> a(n);
    rep(i,n)cin >> a[i];

    int m = a[0][0]-'0';
    rep(i,n)rep(j,n){
        if(a[i][j]-'0' > m){
            m = a[i][j]-'0';
            sx = i;
            sy = j;
        }
    }

    ll ans = -LLONG_MAX;
    rep(i,8){
        string tmp = "";
        int cnt = n,tx = sx,ty = sy;
        while(cnt--){
            tmp += a[(tx%n+n)%n][(ty%n+n)%n];
            tx += dx[i];
            ty += dy[i];
        }
        ans = max(ans,stoll(tmp));
    }
    cout << ans << endl;
    
    return 0;
}