/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc260/submissions/33303608
 * Submitted at: 2022-07-17 21:25:36
 * Problem URL: https://atcoder.jp/contests/abc260/tasks/abc260_c
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

ll n,x,y;
ll ans = 0;
//青が0,赤が1
void dfs(ll num,ll jleve,ll borr){
    if(jleve == 1){
        if(borr == 0)ans += num;
        return;
    }

    if(borr == 1){
        dfs(num,jleve-1,1);
        dfs(num*x,jleve,0);
    }
    else{
        dfs(num,jleve-1,1);
        dfs(num*y,jleve-1,0);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> x >> y;
    dfs(1,n,1);
    cout << ans << endl;
    
    return 0;
}