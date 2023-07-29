/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc312/submissions/44032982
 * Submitted at: 2023-07-29 21:01:45
 * Problem URL: https://atcoder.jp/contests/abc312/tasks/abc312_a
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<string> ss = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    for(auto ele:ss){
        if( ele == s ){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}