/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc312/submissions/44068197
 * Submitted at: 2023-07-29 22:09:32
 * Problem URL: https://atcoder.jp/contests/abc312/tasks/abc312_e
 * Result: AC
 * Execution Time: 422 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<int> dx = {0,-1,0,1,0,0};
vector<int> dy = {-1,0,1,0,0,0};
vector<int> dz = {0,0,0,0,1,-1};

inline bool outField(int x,int y,int z,int h,int w,int d){
    if(0 <= x && x < h && 0 <= y && y < w && 0 <= z && z < d)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector p(105,vector<vector<ll>>(105,vector<ll>(105,0)));
    vector<set<ll>> st(n+1);
    rep(i,n) {
        ll x1,y1,z1,x2,y2,z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for(ll x=x1;x<x2;x++) {
            for(ll y=y1;y<y2;y++) {
                for(ll z=z1;z<z2;z++) {
                    p[x][y][z] = i+1;
                }
            }
        }
    }
    rep(i,101){
        rep(j,101){
            rep(k,101){
                if( p[i][j][k] == 0 ) continue;
                rep(d,6){
                    ll ni = i + dx[d];
                    ll nj = j + dy[d];
                    ll nk = k + dz[d];
                    if( outField(ni,nj,nk,103,103,103) ) continue;
                    if( p[i][j][k] != p[ni][nj][nk] && p[ni][nj][nk] != 0 ) {
                        st[p[i][j][k]].insert(p[ni][nj][nk]);
                    }
                }
            }
        }
    }
    rep(i,n) cout << st[i+1].size() << endl;
    
    return 0;
}