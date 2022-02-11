/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc228/submissions/29211390
 * Submitted at: 2022-02-11 12:42:22
 * Problem URL: https://atcoder.jp/contests/abc228/tasks/abc228_d
 * Result: WA
 * Execution Time: 309 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int n = (1 << 20);

int main() {
    int q; cin >> q;
    vector<ll> a(n,-1);
    vector<ll> seen(n,1);
    rep(i,q){
        int t; ll x; cin >> t >> x;
        if(t == 1){
            int itr1 = lower_bound(seen.begin()+x%n,seen.end(),1)-seen.begin();
            int itr2 = lower_bound(seen.begin(),seen.begin()+x%n-1,1)-seen.begin();
            if(itr1 == n){a[itr2] = x; seen[itr2] = 0;}
            else{a[itr1] = x;  seen[itr1] = 0;}
        }
        else cout << a[x%n] << endl;
    }
    return 0;
}