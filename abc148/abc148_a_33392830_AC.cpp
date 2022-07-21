/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc148/submissions/33392830
 * Submitted at: 2022-07-21 18:24:58
 * Problem URL: https://atcoder.jp/contests/abc148/tasks/abc148_a
 * Result: AC
 * Execution Time: 3 ms
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
    
    map<int,int> ok;
    int a,b; cin >> a >> b;
    ok[a]++; ok[b]++;
    rep(i,3){
        if(!ok[i+1]){
            return cout << i+1 << endl,0;
        }
    }
    
    return 0;
}