/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc061/submissions/31391600
 * Submitted at: 2022-05-02 11:58:02
 * Problem URL: https://atcoder.jp/contests/abc061/tasks/abc061_d
 * Result: AC
 * Execution Time: 15 ms
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
    vector<T> edge;
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        edge.push_back(T(a,b,c));
    }

    vector<ll> p(n,-LLONG_MAX);
    p[0] = 0;
    rep(i,n-1){
        rep(j,m){
            auto [from,to,c] = edge[j];
            if(p[from] == -LLONG_MAX)continue;
            if(p[to] < p[from]+c){
                p[to] = p[from]+c;
            }
        }
    }

    vector<bool> ng(n,false);
    rep(i,n-1){
        rep(j,m){
            auto [from,to,c] = edge[j];
            if(p[from] == -LLONG_MAX)continue;
            if(p[to] < p[from]+c){
                p[to] = p[from]+c;
                ng[to] = true;
            }
        }
    }

    cout << (ng[n-1] ? "inf" : to_string(p[n-1])) << endl;

    return 0;
}