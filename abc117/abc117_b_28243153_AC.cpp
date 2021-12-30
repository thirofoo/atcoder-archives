/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc117/submissions/28243153
 * Submitted at: 2021-12-31 00:42:04
 * Problem URL: https://atcoder.jp/contests/abc117/tasks/abc117_b
 * Result: AC
 * Execution Time: 8 ms
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
    int n,count = 0; cin >> n;
    vector<int> edge(n);
    rep(i,n)cin >> edge[i];
    sort(edge.begin(),edge.end());
    rep(i,n-1)count += edge[i];
    if(count > edge[n-1])cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}