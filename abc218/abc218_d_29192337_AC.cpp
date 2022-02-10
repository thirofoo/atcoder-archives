/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc218/submissions/29192337
 * Submitted at: 2022-02-10 12:06:50
 * Problem URL: https://atcoder.jp/contests/abc218/tasks/abc218_d
 * Result: AC
 * Execution Time: 435 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    ll ans = 0;
    vector<P> e;
    map<P,int> edge;
    rep(i,n){
        int a,b; cin >> a >> b;
        edge[P(a,b)]++;
        e.push_back(P(a,b));
    }
    rep(i,n-1){
        for(int j=i+1;j<n;j++){
            if(e[i].first == e[j].first || e[i].second == e[j].second)continue;
            P e1 = P(e[i].first,e[j].second);
            P e2 = P(e[j].first,e[i].second);
            if(edge[e1] && edge[e2])ans++;
        }
    }
    cout << ans/2 << endl;
    return 0;
}