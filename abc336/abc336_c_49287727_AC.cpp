/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc336/submissions/49287727
 * Submitted at: 2024-01-14 21:06:47
 * Problem URL: https://atcoder.jp/contests/abc336/tasks/abc336_c
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

const string s = "02468";

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    n--;

    // 5進数に変換
    vector<ll> ans;
    while(n > 0) {
        ans.push_back(n % 5);
        n /= 5;
    }
    if( ans.empty() ) ans.push_back(0);
    string str = "";
    for(ll i = ans.size()-1; i >= 0; i--) {
        str += s[ans[i]];
    }
    cout << str << endl;
    
    return 0;
}