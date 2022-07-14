/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc128/submissions/33219219
 * Submitted at: 2022-07-14 18:41:48
 * Problem URL: https://atcoder.jp/contests/abc128/tasks/abc128_b
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<string, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<T> r;
    rep(i,n){
        int p;string s; cin >> s >> p;
        r.push_back(T(s,100-p,i));
    }
    sort(r.begin(),r.end());
    for(auto [S,P,idx]:r){
        cout << idx+1 << endl;
    }
    
    return 0;
}