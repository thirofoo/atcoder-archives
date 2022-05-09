/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc250/submissions/31574392
 * Submitted at: 2022-05-10 00:08:41
 * Problem URL: https://atcoder.jp/contests/abc250/tasks/abc250_e
 * Result: AC
 * Execution Time: 876 ms
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
    
    int n; cin >> n;
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    map<int,int> idxa,idxb;
    rep(i,n){
        if(idxa[a[i]] == 0)idxa[a[i]] = i+1;
        if(idxb[b[i]] == 0)idxb[b[i]] = i+1;
    }
    vector<int> dpA(n+1,INT_MAX),dpB(n+1,INT_MAX);
    dpA[0] = 0; dpB[0] = 0;
    rep(i,n){
        dpA[i+1] = max(dpA[i],idxb[a[i]] == 0 ? INT_MAX : idxb[a[i]]);
        dpB[i+1] = max(dpB[i],idxa[b[i]] == 0 ? INT_MAX : idxa[b[i]]);
    }
    int q; cin >> q;
    rep(i,q){
        int x,y; cin >> x >> y;
        if(dpA[x] <= y && dpB[y] <= x)cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}