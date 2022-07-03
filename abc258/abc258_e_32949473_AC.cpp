/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/32949473
 * Submitted at: 2022-07-03 12:00:38
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_e
 * Result: AC
 * Execution Time: 542 ms
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
    
    ll n,q,x,total = 0; cin >> n >> q >> x;
    vector<int> w(n);
    rep(i,n){
        cin >> w[i];
        total += w[i];
    }
    //頂点iから初めた時に何個のジャガイモを入れられるかを予め求めておく
    //cycle : 頂点iからジャガイモを詰めるときに必要なジャガイモの個数
    vector<vector<int>> doubling(64,vector<int>(n,0));
    vector<int> cycle(n);
    ll l = 0,r = 0,now = x%total;
    while(l < n){
        if(now <= 0){
            cycle[l] = r-l + x/total*n;
            now += w[l];
            //doubling初期値設定
            doubling[0][l] = r%n;
            l++;
        }
        else{
            now -= w[r%n];
            r++;
        }
    }

    //2^i回箱の蓋を閉じた時の次の位置をダブリングで求める
    for(int i=1;i<64;i++)rep(j,n){
        //jから初めて2^i回操作した後の位置
        //doubling[i-1][j] : j始点で0~2^(i-1)回操作後の場所
        //doubling[i-1][doubling[i-1][j]] : doubling[i-1][j]始点で2^(i-1)+1~2^i回操作後の場所
        doubling[i][j] = doubling[i-1][doubling[i-1][j]];
    }


    while(q--){
        //vertex : k-1回目まで遂行された後の頂点を求める
        ll k; cin >> k; k--;
        ll vertex = 0;
        rep(i,64){
            if(k & (1LL << i)){
                vertex = doubling[i][vertex];
            }
        }
        cout << cycle[vertex] << endl;
    }
    
    return 0;
}