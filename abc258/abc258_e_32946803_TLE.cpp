/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/32946803
 * Submitted at: 2022-07-03 08:42:47
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_e
 * Result: TLE
 * Execution Time: 2206 ms
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
    // ll cnt = 0;
    // for(auto l:Graph){
    //     cout << "now : " << cnt << " / ";
    //     for(auto m:l)cout << m << " ";
    //     cout << ". next : " << cycle[cnt] << endl;
    //     cnt++;
    // }
    ll sx = 0,cx = 0;
    vector<ll> visited(n,0);
    while(true){
        if(visited[sx])break;
        visited[sx] = visited[cx]+1;
        cx = sx;
        sx = Graph[sx][0];
    }
    while(q--){
        ll k; cin >> k;
        k--;
        if(k <= visited[sx]-1){
            rep(i,n)if(visited[i]-1 == k){
                cout << cycle[i] << endl;
                break;
            }   
        }
        else{
            k -= visited[sx]-1;
            ll T = visited[cx]-visited[sx]+1;
            k %= T;
            rep(i,n)if(visited[i] == k+visited[sx]){
                cout << cycle[i] << endl;
                break;
            }   
        }
    }
    
    return 0;
}