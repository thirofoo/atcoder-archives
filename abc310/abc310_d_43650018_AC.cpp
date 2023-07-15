/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc310/submissions/43650018
 * Submitted at: 2023-07-16 00:25:07
 * Problem URL: https://atcoder.jp/contests/abc310/tasks/abc310_d
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
    int n, t, m, ans = 0; cin >> n >> t >> m;
    vector<int> ng(n,0), team(t,0);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        ng[a] |= (1 << b);
        ng[b] |= (1 << a);
    }
    auto f = [&](auto self, int now){
        if( now == n ){
            bool flag = true;
            rep(i,t) flag &= (team[i] > 0);
            if( flag )ans++;
            return;
        }
        rep(i,t){
            if( ng[now] & team[i] )continue;
            team[i] ^= (1 << now);
            self(self, now+1);
            team[i] ^= (1 << now);
            if( !team[i] ) break;
        }
    };

    f(f, 0);
    cout << ans << endl;
    
    return 0;
}