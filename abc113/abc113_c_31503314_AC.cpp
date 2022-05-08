/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc113/submissions/31503314
 * Submitted at: 2022-05-08 11:14:59
 * Problem URL: https://atcoder.jp/contests/abc113/tasks/abc113_c
 * Result: AC
 * Execution Time: 334 ms
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m; cin >> n >> m;
    map<int,vector<int>> classed;
    vector<P> city;
    rep(i,m){
        int p,y; cin >> p >> y;
        city.push_back(P(p,y));
        classed[p].push_back(y);
    }
    for(auto [key,val]:classed)sort(classed[key].begin(),classed[key].end());
    rep(i,m){
        auto [p,y] = city[i];
        string str1 = to_string(p);
        string str2 = to_string(lower_bound(classed[p].begin(),classed[p].end(),y)-classed[p].begin()+1);
        while(str1.size() < 6)str1 = "0" + str1;
        while(str2.size() < 6)str2 = "0" + str2;
        cout << str1 << str2 << endl;
    }

    return 0;
}