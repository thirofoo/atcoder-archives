/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc263/submissions/33814282
 * Submitted at: 2022-08-06 21:14:51
 * Problem URL: https://atcoder.jp/contests/abc263/tasks/abc263_c
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll n,m; cin >> n >> m;
    vector<vector<int>> ans;
    for(ll now = 1;now < (1LL << m);now++){
        ll num = 0;
        rep(i,m)if(now & (1LL << i))num++;
        if(num == n){
            vector<int> tmp;
            rep(i,m)if(now & (1LL << i))tmp.push_back(i+1);
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto k:ans){
        for(auto l:k){
            cout << l << " ";
        }
        cout << endl;
    }
    
    return 0;
}