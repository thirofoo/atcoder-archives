/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc265/submissions/34221378
 * Submitted at: 2022-08-21 21:29:08
 * Problem URL: https://atcoder.jp/contests/abc265/tasks/abc265_d
 * Result: WA
 * Execution Time: 44 ms
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
    
    ll n,p,q,r; cin >> n >> p >> q >> r;
    vector<ll> a(n+1,0);
    rep(i,n)cin >> a[i+1];
    rep(i,n)a[i+1] += a[i];
    
    //xを全探索
    int y,z,w;
    for(int x=1;x<=n;x++){
        auto i1 = lower_bound(a.begin(),a.end(),a[x]+p);
        if(i1 != a.end() && *i1 == a[x]+p){
            auto i2 = lower_bound(a.begin(),a.end(),a[x]+p+q);
            if(i2 != a.end() && *i2 == a[x]+p+q){
                auto i3 = lower_bound(a.begin(),a.end(),a[x]+p+q+r);
                if(i3 != a.end() && *i3 == a[x]+p+q+r)return cout << "Yes" << endl,0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}