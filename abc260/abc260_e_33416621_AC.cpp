/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc260/submissions/33416621
 * Submitted at: 2022-07-23 02:40:21
 * Problem URL: https://atcoder.jp/contests/abc260/tasks/abc260_e
 * Result: AC
 * Execution Time: 102 ms
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
    
    ll n,m,cnt = 0; cin >> n >> m;
    vector<vector<ll>> where(m+1);
    vector<ll> now(n,0),ans(m+2,0);
    rep(i,n){
        ll a,b; cin >> a >> b;
        where[a].push_back(i);
        where[b].push_back(i);
    }

    //連続部分列 → 尺取りで区間を指定して計算
    ll left = 1,right = 1;
    while(left < m+1){
        if(cnt == n){
            ans[right-left]++;
            ans[m-left+2]--;
        }
        if(right == m+1 || cnt == n){
            for(auto k:where[left]){
                now[k]--;
                if(now[k] == 0)cnt--;
            }
            ++left;
        }
        else{
            for(auto k:where[right]){
                now[k]++;
                if(now[k] == 1)cnt++;
            }
            ++right;
        }
    }

    //区間更新はimos法
    rep(i,m)ans[i+1] += ans[i];

    //答え出力
    rep(i,m)cout << ans[i+1] << " ";
    cout << endl;
    return 0;
}