/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc224/submissions/28826450
 * Submitted at: 2022-01-27 21:03:12
 * Problem URL: https://atcoder.jp/contests/abc224/tasks/abc224_c
 * Result: AC
 * Execution Time: 25 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,count = 0; cin >> n;
    vector<P> edge;
    rep(i,n){
        ll a,b; cin >> a >> b;
        edge.push_back(P(a,b));
    }
    rep(i,n){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(edge[k].first == edge[i].first && edge[j].first == edge[k].first){
                    continue;
                }
                else if(edge[k].first == edge[i].first || edge[j].first == edge[k].first){
                    count++; continue;
                }
                ll tilt_1 = (edge[k].second-edge[i].second)*(edge[j].first-edge[k].first);
                ll tilt_2 = (edge[j].second-edge[k].second)*(edge[k].first-edge[i].first);
                // cout << tilt_1 << " " << tilt_2 << endl;
                if(tilt_1 != tilt_2)count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}