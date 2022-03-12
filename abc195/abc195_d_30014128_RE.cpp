/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc195/submissions/30014128
 * Submitted at: 2022-03-12 09:50:18
 * Problem URL: https://atcoder.jp/contests/abc195/tasks/abc195_d
 * Result: RE
 * Execution Time: 113 ms
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
    int n,m,q; cin >> n >> m >> q;
    vector<P> vw;
    vector<int> x(m);
    rep(i,n){
        int a,b; cin >> a >> b;
        vw.push_back(P(b,a));
    }
    rep(i,m)cin >> x[i];
    sort(vw.begin(),vw.end());

    rep(i,q){
        int l,r; cin >> l >> r;
        l--; r--;
        vector<int> todo;
        rep(j,m){
            if(l <= j && j <= r)continue;
            todo.push_back(x[j]);
        }
        sort(todo.begin(),todo.end());

        vector<bool> visited(n,false);
        map<int,int> value;
        int tmp = -1,ans = 0;
        rep(j,todo.size()){
            rep(k,n){
                if(visited[k])continue;
                auto [v,w] = vw[k];
                if(w <= todo[j] && v > value[j]){
                    value[j] = v;
                    tmp = k;
                }
            }
            visited[tmp] = true;
            ans += vw[tmp].first;
        }
        cout << ans << '\n';
    }
    return 0;
}