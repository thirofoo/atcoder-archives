/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc246/submissions/30633353
 * Submitted at: 2022-04-02 21:09:18
 * Problem URL: https://atcoder.jp/contests/abc246/tasks/abc246_c
 * Result: TLE
 * Execution Time: 2205 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,k,x; cin >> n >> k >> x;
    priority_queue<int> v;
    rep(i,n){
        int a; cin >> a;
        v.push(a);
    }

    while(k--){
        int tmp = v.top(); v.pop();
        tmp = max(0,tmp-x);
        v.push(tmp);
    }

    ll ans = 0;
    while(!v.empty()){
        ans += v.top(); v.pop();
    }
    cout << ans << endl;
    return 0;
}