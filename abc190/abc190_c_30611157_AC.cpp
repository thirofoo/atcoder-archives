/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc190/submissions/30611157
 * Submitted at: 2022-04-02 00:03:17
 * Problem URL: https://atcoder.jp/contests/abc190/tasks/abc190_c
 * Result: AC
 * Execution Time: 34 ms
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
    int n,m; cin >> n >> m;
    vector<P> ok;
    queue<P> query;
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        ok.push_back(P(a,b));
    }

    int k,ans = 0; cin >> k;
    rep(i,k){
        int c,d; cin >> c >> d;
        c--; d--;
        query.push(P(c,d));
    }
    for(int i=0;i<(1 << k);i++){
        vector<bool> frag(n,false);
        rep(j,k){
            auto [c,d] = query.front(); query.pop();
            if(i & (1 << j))frag[d] = true;
            else frag[c] = true;
            query.push(P(c,d));
        }
        int tmp = 0;
        rep(j,m){
            auto [a,b] = ok[j];
            if(frag[a] && frag[b])tmp++;
        }
        ans = max(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}