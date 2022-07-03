/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/32947502
 * Submitted at: 2022-07-03 09:56:58
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_e
 * Result: AC
 * Execution Time: 367 ms
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
    vector<int> w(2*n);
    rep(i,n){
        cin >> w[i];
        w[i+n] = w[i];
        total += w[i];
    }
    //part1 : 尺取りで1箱先を求めて有向辺を張る
    vector<vector<int>> Graph(n);
    //cycle : 頂点iにいるときに
    vector<int> cycle(n,INT_MAX);
    cycle[0] = 0;
    ll right = 0,now = 0;
    for(int left=0;left<n;left++){
        while(x%total > now){
            now += w[right];
            right++;
        }
        Graph[left].push_back(right%n);
        cycle[left] = right-left + x/total*n;
        now -= w[left];
    }
    
    //part2 : サイクルの周期性を活かす

    //c1 : サイクルの始点 c2 : サイクルの終点
    ll sx = 0,c1,c2,cnt = 0;
    //p : cnt-1箱目の蓋を占めた時どこの頂点にいるか(必ずcnt <= nまでにサイクルが出来る)
    //pre : 頂点iに以前来たのはいつか
    vector<ll> p(n+1,0),pre(n,-1);
    while(true){
        if(pre[sx] >= 0){
            c1 = pre[sx];
            c2 = pre[p[cnt-1]];
            break;
        }
        p[cnt] = sx;
        pre[sx] = cnt;
        sx = Graph[sx][0];
        cnt++;
    }
    // cout << endl;
    // rep(i,n)cout << p[i] << " ";
    // cout << endl;
    // cout << c1 << " " << c2 << endl;

    //T : 周期
    ll T = c2-c1+1;
    while(q--){
        ll k; cin >> k; k--;
        if(k < c1){
            cout << cycle[p[k]] << endl;
        }
        else{
            cout << cycle[p[c1 + (k-c1)%T]] << endl;
        }
    }
    
    return 0;
}