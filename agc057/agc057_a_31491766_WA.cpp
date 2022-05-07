/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc057/submissions/31491766
 * Submitted at: 2022-05-07 22:01:26
 * Problem URL: https://atcoder.jp/contests/agc057/tasks/agc057_a
 * Result: WA
 * Execution Time: 31 ms
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
    
    int t; cin >> t;
    rep(i,t){
        string l,r; cin >> l >> r;
        if(r.size() == l.size())cout << stoi(r)-stoi(l)+1 << endl;
        else if(r[0] != '1')cout << stoi(r)-max((int)pow(10,r.size()-1),stoi(l))+1 << endl;
        else if(r[1] != '0')cout << min((int)pow(10,r.size()-1),stoi(r)-stoi(l)) << endl;
        else cout << stoi(r)-max(stoi(l),(int)pow(10,r.size()-2)) << endl;
    }
    return 0;
}