/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/28629266
 * Submitted at: 2022-01-19 14:30:23
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_e
 * Result: WA
 * Execution Time: 594 ms
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
typedef tuple<int, int, int, int> t4;
 
int main(){
    int n,m,q; cin >> n >> m >> q;
    vector<t4> edge;
    vector<vector<int>> tree(n);
    dsu d(n);
    rep(i,m+q){
        int a,b,c; cin >> a >> b >> c;
        edge.push_back(t4(c,a-1,b-1,i));
    }
    sort(edge.begin(),edge.end());
    vector<bool> ans(q,false);
    rep(i,m+q){
        auto [w,a,b,size] = edge[i];
        if(!d.same(a,b)){
            d.merge(a,b);
            if(size >= m)ans[size-m] = true;
        }
    }
    rep(i,q){
        if(ans[i])cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}