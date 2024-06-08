/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc357/submissions/54325942
 * Submitted at: 2024-06-08 21:03:05
 * Problem URL: https://atcoder.jp/contests/abc357/tasks/abc357_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    ll dai = 0, syo = 0;
    rep(i,s.size()) {
        if('A' <= s[i] && s[i] <= 'Z') dai++;
        else syo++;
    }
    rep(i,s.size()) {
        if(dai > syo && 'a' <= s[i] && s[i] <= 'z') s[i] = toupper(s[i]);
        else if(dai < syo && 'A' <= s[i] && s[i] <= 'Z') s[i] = tolower(s[i]);
    }
    cout << s << endl;
    
    return 0;
}