/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc130/submissions/30805724
 * Submitted at: 2022-04-09 18:31:13
 * Problem URL: https://atcoder.jp/contests/arc130/tasks/arc130_b
 * Result: AC
 * Execution Time: 388 ms
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
    ll h,w,c,q,row = 0,column = 0; cin >> h >> w >> c >> q;
    vector<ll> ans(c+1,0);
    map<ll,bool> r_used,c_used;
    stack<T> query;
    rep(i,q){
        ll t,n,c; cin >> t >> n >> c;
        n--;
        query.push(T(t,n,c));
    }
    while(!query.empty()){
        auto [t,n,c] = query.top(); query.pop();
        if(t == 1 && !r_used[n]){
            r_used[n] = true;
            ans[c] += w-column;
            row++;
        }
        else if(t == 2 && !c_used[n]){
            c_used[n] = true;
            ans[c] += h-row;
            column++;
        }
    }
    rep(i,c)cout << ans[i+1] << " ";
    cout << endl;
    return 0;
}