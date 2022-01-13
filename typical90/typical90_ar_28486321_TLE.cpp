/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28486321
 * Submitted at: 2022-01-13 10:39:00
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ar
 * Result: TLE
 * Execution Time: 2205 ms
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
    int n,q; cin >> n >> q;
    vector<int> seq(n);
    rep(i,n) cin >> seq[i];
    rep(i,q){
        int a,b,c; cin >> a >> b >> c;
        if(a == 1) swap(seq[b-1],seq[c-1]);
        else if(a == 2){
            seq.insert(seq.begin(),*(seq.end()-1));
            seq.pop_back();
        }
        else cout << seq[b-1] << endl;
    }
    return 0;
}