/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc045/submissions/44240130
 * Submitted at: 2023-08-05 08:28:51
 * Problem URL: https://atcoder.jp/contests/abc045/tasks/arc061_b
 * Result: AC
 * Execution Time: 762 ms
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
    // 各黒マスが入る上下5マスズレを全探索
    vector<ll> cnt(10,0);
    set<P> p;
    set<P> st;
    rep(i,n) {
        ll a,b; cin >> a >> b;
        p.insert( P(a,b) );
    }
    for(auto [a,b]:p) {
        for(ll dx=-2;dx<=0;dx++) {
            for(ll dy=-2;dy<=0;dy++) {
                ll nx = a + dx, ny = b + dy;
                if( st.count(P(nx,ny)) || outField(nx,ny,h,w) || outField(nx+2,ny+2,h,w) ) continue;
                st.insert( P(nx,ny) );
                ll total = 0;
                rep(j,3) {
                    rep(k,3) {
                        if( p.count( P(nx+j,ny+k) ) ) total++;
                    }
                }
                // cout << "P(" << nx << "," << ny << ")" << " : " << total << endl;
                cnt[total]++;
            }
        }
    }
    cnt[0] = (h-2)*(w-2);
    rep(i,9) cnt[0] -= cnt[i+1];
    rep(i,10) cout << cnt[i] << endl;
    
    return 0;
}