/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc097/submissions/28606307
 * Submitted at: 2022-01-17 23:48:39
 * Problem URL: https://atcoder.jp/contests/abc097/tasks/arc097_b
 * Result: AC
 * Execution Time: 71 ms
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

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { 
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x); 
        int ry = root(y); 
        if (rx == ry) return; 
        par[rx] = ry; 
    }

    bool same(int x, int y) { 
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int n,m; cin >> n >> m;
    vector<int> p(n);
    rep(i,n)cin >> p[i];
    UnionFind tree(n);
    rep(i,m){
        int x,y; cin >> x >> y;
        tree.unite(x-1,y-1);
    }
    int cnt = 0;
    rep(i,n){
        if(tree.same(i,p[i]-1))cnt++;
    }
    cout << cnt << endl;
    return 0;
}