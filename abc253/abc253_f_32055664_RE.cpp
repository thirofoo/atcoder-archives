/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/32055664
 * Submitted at: 2022-05-28 22:39:48
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_f
 * Result: RE
 * Execution Time: 2206 ms
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
    
    int n,m,q; cin >> n >> m >> q;
    vector<ll> row(n,0),column(m,0);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l,r,x; cin >> l >> r >> x;
            l--; r--;
            for(int i=l-1;i<=r;i++)column[i] += x;
        }
        else if(t == 2){
            int I,x; cin >> I >> x;
            I--;
            rep(j,n)row[I] = x-column[j];
        }
        else{
            int I,J; cin >> I >> J;
            I--; J--;
            cout << row[I]+column[J] << endl;
        }
    }

    return 0;
}