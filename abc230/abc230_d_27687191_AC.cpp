/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/27687191
 * Submitted at: 2021-12-04 17:20:27
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_d
 * Result: AC
 * Execution Time: 129 ms
 */

#include <bits/stdc++.h>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    int n,d;
    int j = 1;
    int ans = 0;
    cin >> n >> d;
    vector<P> wall(n);
    rep(i,n)cin >> wall[i].first >> wall[i].second;
    sort(wall.begin(),wall.end(),[](P& c, P& d) {
        return c.second < d.second;
    });
    int i=0;
    while(i<n){
        while (j < n && wall[j].first - wall[i].second < d) ++j;
        i = j;
        ans++;
    }
    cout << ans << endl;
    return 0;
}