/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/31026412
 * Submitted at: 2022-04-16 21:37:42
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_d
 * Result: WA
 * Execution Time: 783 ms
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
    int n,q; cin >> n;
    map<int,vector<int>> b;
    rep(i,n){
        int tmp; cin >> tmp;
        b[tmp].push_back(i);
    }
    rep(i,n)sort(b[i+1].begin(),b[i+1].end());
    cin >> q;
    rep(i,q){
        int l,r,x; cin >> l >> r >> x;
        l--; r--;
        auto itr1 = lower_bound(b[x].begin(),b[x].end(),l);
        auto itr2 = lower_bound(b[x].begin(),b[x].end(),r);
        cout << itr2-itr1 << endl;
    }
    return 0;
}