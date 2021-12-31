/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc183/submissions/28250550
 * Submitted at: 2021-12-31 11:01:27
 * Problem URL: https://atcoder.jp/contests/abc183/tasks/abc183_c
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
    ll n,k,count = 0; cin >> n >> k;
    vector<vector<ll>> time(n,vector<ll>(n));
    rep(i,n)rep(j,n)cin >> time[i][j];
    vector<int> perm(n-1);
    iota(perm.begin(),perm.end(),2);
    do{
        ll total = 0;
        total += time[0][perm[0]-1];
        rep(i,n-2)total += time[perm[i]-1][perm[i+1]-1];
        total += time[perm[n-2]-1][0];
        if(total == k)count++;
    }while(next_permutation(perm.begin(),perm.end()));
    cout << count << endl;
    return 0;
}