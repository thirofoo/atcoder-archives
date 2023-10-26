/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46943556
 * Submitted at: 2023-10-26 18:33:21
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc293_a
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    for(int i=0; i<s.size(); i+=2) swap(s[i],s[i+1]);
    cout << s << endl;
    
    return 0;
}