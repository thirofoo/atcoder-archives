/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/28546941
 * Submitted at: 2022-01-15 21:27:04
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_c
 * Result: AC
 * Execution Time: 759 ms
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
    int n,q; cin >> n >> q;
    map<int,vector<int>> seq;
    rep(i,n){
        int a; cin >> a;
        seq[a].push_back(i+1);
    }
    rep(i,q){
        int a,b; cin >> a >> b;
        if(seq[a].size() >= b)cout << seq[a][b-1] << endl;
        else cout << -1 << endl;
    }
    return 0;
}