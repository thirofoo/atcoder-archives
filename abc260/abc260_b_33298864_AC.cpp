/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc260/submissions/33298864
 * Submitted at: 2022-07-17 21:12:37
 * Problem URL: https://atcoder.jp/contests/abc260/tasks/abc260_b
 * Result: AC
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,x,y,z; cin >> n >> x >> y >> z;
    priority_queue<ll,vector<ll>,greater<ll>> ans;
    vector<P> a,b,c;
    vector<bool> ok(n,false);
    rep(i,n){
        int tmp; cin >> tmp;
        a.push_back(P(tmp,n-i));
    }
    rep(i,n){
        int tmp; cin >> tmp;
        b.push_back(P(tmp,n-i));
    }
    rep(i,n){
        auto [m,i1] = a[i];
        auto [e,i2] = b[i];
        c.push_back(P(m+e,n-i));
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());

    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    rep(i,x){
        auto [m,idx] = a[i];
        ok[n-idx] = true;
        ans.push(n-idx+1);
    }
    rep(i,n){
        if(y == 0)break;
        auto [e,idx] = b[i];
        if(!ok[n-idx]){
            ok[n-idx] = true;
            ans.push(n-idx+1);
            y--;
        }
    }
    rep(i,n){
        if(z == 0)break;
        auto [total,idx] = c[i];
        if(!ok[n-idx]){
            ok[n-idx] = true;
            ans.push(n-idx+1);
            z--;
        }
    }
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }
    
    return 0;
}