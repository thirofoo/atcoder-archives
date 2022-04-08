/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc189/submissions/30794494
 * Submitted at: 2022-04-09 00:09:53
 * Problem URL: https://atcoder.jp/contests/abc189/tasks/abc189_e
 * Result: AC
 * Execution Time: 710 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

//90°の回転移動の行列
vector<vector<ll>> l_rotate(3,vector<ll>(3,0)),r_rotate(3,vector<ll>(3,0));

//線対称移動の行列
vector<vector<ll>> symmetry(3,vector<ll>(3,0));

//3*3と3*1行列の積。
vector<ll> solve(vector<vector<ll>>& affine, vector<ll>& p){
    vector<ll> ans(3,0);
    rep(i,3){
        rep(j,3)ans[i] += affine[i][j]*p[j];
    }
    return ans;
}

//3*3と3*3の行列の積。
vector<vector<ll>> solve2(vector<vector<ll>>& p1,vector<vector<ll>>& p2){
    vector<vector<ll>> ans(3,vector<ll>(3,0));
    rep(i,3){
        rep(j,3){
            rep(k,3){
                ans[i][j] += p1[i][k]*p2[k][j];
            }
        }
    }
    return ans;
}

int main() {
    //入力受付
    ll n; cin >> n;
    vector<vector<ll>> vertex(n);
    rep(i,n){
        ll x,y; cin >> x >> y;
        vertex[i].push_back(x);
        vertex[i].push_back(y);
        vertex[i].push_back(1);
    }

    //回転行列作成部分
    r_rotate[0][1] = 1; r_rotate[1][0] = -1; r_rotate[2][2] = 1;
    l_rotate[0][1] = -1; l_rotate[1][0] = 1; l_rotate[2][2] = 1;
    //線対称移動行列作成部分
    symmetry[0][0] = 1; symmetry[1][1] = -1; symmetry[2][2] = 1;

    //アフィン変換主要部
    ll m; cin >> m;
    vector<vector<vector<ll>>> process(m+1,vector<vector<ll>>(3,vector<ll>(3,0)));
    rep(i,3)process[0][i][i] = 1;
    rep(i,m){
        ll t,p = 0; cin >> t;
        if(t == 3 || t == 4)cin >> p;
        switch(t){
            case 1:
                process[i+1] = solve2(r_rotate,process[i]);
                break;
            case 2:
                process[i+1] = solve2(l_rotate,process[i]);
                break;
            case 3:
                symmetry[0][2] = 2*p;
                symmetry[0][0] *= -1; symmetry[1][1] *= -1;
                process[i+1] = solve2(symmetry,process[i]);
                symmetry[0][0] *= -1; symmetry[1][1] *= -1;
                symmetry[0][2] = 0;
                break;
            case 4:
                symmetry[1][2] = 2*p;
                process[i+1] = solve2(symmetry,process[i]);
                symmetry[1][2] = 0;
                break;
        };
    }

    //答え出力part。
    ll q; cin >> q;
    rep(i,q){
        ll a,b; cin >> a >> b; b--;
        vector<ll> ans = solve(process[a],vertex[b]);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}