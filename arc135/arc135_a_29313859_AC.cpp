/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc135/submissions/29313859
 * Submitted at: 2022-02-13 22:34:13
 * Problem URL: https://atcoder.jp/contests/arc135/tasks/arc135_a
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

map<ll,mint> memo;

void dfs(ll x){
    if(x <= 4)memo[x] = x;
    else if(memo.count(x/2) && memo.count((x+1)/2))memo[x] = memo[x/2]*memo[(x+1)/2];
    else{
        dfs(x/2);
        dfs((x+1)/2);
        memo[x] = memo[x/2]*memo[(x+1)/2];
    }
}

int main() {
    ll x; cin >> x;
    dfs(x);
    cout << memo[x].val() << endl;
    return 0;
}