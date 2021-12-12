/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/27882152
 * Submitted at: 2021-12-12 20:46:45
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_c
 * Result: AC
 * Execution Time: 434 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,q;
    cin >> n >> q;
    vector<ll> tall(n);
    vector<ll> base(q);
    rep(i,n)cin >> tall[i];
    rep(i,q)cin >> base[i];
    sort(tall.begin(),tall.end());
    rep(i,q){
        auto itr = lower_bound(tall.begin(),tall.end(),base[i]);
        cout << n - (itr - tall.begin()) << endl;
    }
    return 0;
}