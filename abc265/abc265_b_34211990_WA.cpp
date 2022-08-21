/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc265/submissions/34211990
 * Submitted at: 2022-08-21 21:14:35
 * Problem URL: https://atcoder.jp/contests/abc265/tasks/abc265_b
 * Result: WA
 * Execution Time: 34 ms
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m,t; cin >> n >> m >> t;
    vector<ll> a(n),b(n,0);
    rep(i,n-1)cin >> a[i];
    rep(i,m){
        int x,y; cin >> x >> y; x--;
            b[x] = y;
    }
    int now = 0;
    while(now != n){
        if(t >= a[now]){
            t -= a[now];
            t += b[now+1];
            now++;
        }
        else break;
    }
    cout << (now == n ? "Yes" : "No") << endl;
    
    return 0;
}