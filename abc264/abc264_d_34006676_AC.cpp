/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc264/submissions/34006676
 * Submitted at: 2022-08-13 21:43:51
 * Problem URL: https://atcoder.jp/contests/abc264/tasks/abc264_d
 * Result: AC
 * Execution Time: 8 ms
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
    
    string s; cin >> s;
    string a = "atcoder";
    map<char,int> c;
    rep(i,7)c[a[i]] = i+1;

    fenwick_tree<int> fw(8);
    int ans = 0;
    rep(i,7){
        fw.add(c[s[i]]-1,1);
        ans += fw.sum(c[s[i]],8);
    }
    cout << ans << endl;
    
    return 0;
}