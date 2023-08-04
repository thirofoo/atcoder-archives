/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc045/submissions/44240224
 * Submitted at: 2023-08-05 08:42:21
 * Problem URL: https://atcoder.jp/contests/abc045/tasks/arc061_b
 * Result: AC
 * Execution Time: 316 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

inline bool outField(int x,int y,int h,int w){
    if(1 <= x && x <= h && 1 <= y && y <= w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w,n; cin >> h >> w >> n;
    // 解説ver 各マスの貢献度をカウント (主客転倒)
    map<ll,ll> cnt;
    set<P> p;
    set<P> st;
    rep(i,n) {
        ll a,b; cin >> a >> b;
        p.insert( P(a,b) );
    }
    ll sum = 0;
    for(auto [a,b]:p) {
        for(ll dx=-2;dx<=0;dx++) {
            for(ll dy=-2;dy<=0;dy++) {
                ll nx = a + dx, ny = b + dy;
                if( outField(nx,ny,h,w) || outField(nx+2,ny+2,h,w) ) continue;
                cnt[(nx-1)*w + ny]++;
            }
        }
    }
    vector<ll> ans(10,0);
    ans[0] = (h-2)*(w-2) - cnt.size();
    for(auto [key,value]:cnt) ans[value]++;
    rep(i,10) cout << ans[i] << endl;

    return 0;
}