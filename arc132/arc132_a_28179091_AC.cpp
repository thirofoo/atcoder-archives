/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc132/submissions/28179091
 * Submitted at: 2021-12-26 22:57:58
 * Problem URL: https://atcoder.jp/contests/arc132/tasks/arc132_a
 * Result: AC
 * Execution Time: 90 ms
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
    int n,q;
    cin >> n;
    vector<int> perm1(n),perm2(n);
    rep(i,n)cin >> perm1[i];
    rep(i,n)cin >> perm2[i];
    cin >> q;
    string ans = "";
    rep(i,q){
        int a,b;
        cin >> a >> b;
        if(perm1[a-1]+perm2[b-1] <= n)ans.insert(ans.size(),".");
        else ans.insert(ans.size(),"#");
    }
    cout << ans << endl;
    return 0;
}