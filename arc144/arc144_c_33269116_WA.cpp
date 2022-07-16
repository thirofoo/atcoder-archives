/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc144/submissions/33269116
 * Submitted at: 2022-07-16 22:10:57
 * Problem URL: https://atcoder.jp/contests/arc144/tasks/arc144_c
 * Result: WA
 * Execution Time: 30 ms
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
    
    ll n,k; cin >> n >> k;
    if(n/2 < k)return cout << -1 << endl,0;
    deque<ll> ans;
    rep(i,n)ans.push_back(i+1);
    rep(i,k){
        ans.push_back(ans.front());
        ans.pop_front();
    }
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop_front();
    }
    cout << endl;
    
    return 0;
}