/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28476195
 * Submitted at: 2022-01-12 16:22:13
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_af
 * Result: AC
 * Execution Time: 275 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);

    int n,ans = 10001; cin >> n;
    vector<vector<int>> time(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> time[i][j];
    int m; cin >> m;
    vector<int> mem(n);
    vector<P> hate;
    rep(i,m){
        int a,b; cin >> a >> b;
        hate.push_back(P(a,b));
    }
    iota(mem.begin(),mem.end(),1);

    do{
        bool frag = false;
        rep(i,m){
            int a,b; tie(a,b) = hate[i];
            if(*find(mem.begin(),mem.end(),a) != *(mem.end()-1) && *(find(mem.begin(),mem.end(),a)+1) == b){frag = true; break;}
            if(*find(mem.begin(),mem.end(),a) != *mem.begin() && *(find(mem.begin(),mem.end(),a)-1) == b){frag = true; break;}
        }
        if(frag)continue;
        int times = 0;
        rep(i,n) times += time[mem[i]-1][i];
        ans = min(ans,times);
    }while(next_permutation(mem.begin(),mem.end()));

    if(ans != 10001) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}