/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/28320516
 * Submitted at: 2022-01-04 16:07:14
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_c
 * Result: AC
 * Execution Time: 431 ms
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
    ll n,a,b,p,q,r,s; cin >> n >> a >> b >> p >> q >> r >> s;
    for(ll row=p;row<=q;row++){
        string tmp = "";
        for(ll col=r;col<=s;col++){
            if(row+col == a+b || row-col == a-b)tmp.push_back('#');
            else tmp.push_back('.');
        }
        cout << tmp << endl;
    }
    return 0;
}