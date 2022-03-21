/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30324351
 * Submitted at: 2022-03-21 16:53:01
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_j
 * Result: WA
 * Execution Time: 241 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<int> a1,a2;
    a1.push_back(0);
    a2.push_back(0);
    rep(i,n){
        int c,p; cin >> c >> p;
        int tmp1 = (c == 1 ? a1.back()+p : a1.back());
        int tmp2 = (c == 2 ? a2.back()+p : a2.back());
        a1.push_back(tmp1);
        a2.push_back(tmp2);
    }

    rep(i,n)cout << a1[i] << " ";
    cout << endl;
    rep(i,n)cout << a2[i] << " ";
    cout << endl;

    int q; cin >> q;
    rep(i,q){
        int l,r; cin >> l >> r;
        cout << a1[r]-a1[l-1] << " " << a2[r]-a2[l-1] << endl;
    }
    return 0;
}