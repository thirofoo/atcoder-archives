/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc132/submissions/28175220
 * Submitted at: 2021-12-26 21:59:50
 * Problem URL: https://atcoder.jp/contests/arc132/tasks/arc132_b
 * Result: AC
 * Execution Time: 36 ms
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
    int n,ans; cin >> n;
    vector<int> perm(n);
    rep(i,n)cin >> perm[i];
    ll place_1 = find(perm.begin(),perm.end(),1) - perm.begin();
    ll place_n = find(perm.begin(),perm.end(),n) - perm.begin();
    if(perm[0] == 1 && perm[n-1] == n)return cout << 0 << endl,0;
    else if(place_n > place_1){
        ans = min(1+perm.end()-find(perm.begin(),perm.end(),n),2+find(perm.begin(),perm.end(),1)-perm.begin());
    }
    else{
        ans = min(1+find(perm.begin(),perm.end(),n)-perm.begin(),2+perm.end()-find(perm.begin(),perm.end(),1));
    }
    cout << ans << endl;
    return 0;
}