/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/practice2/submissions/29769993
 * Submitted at: 2022-02-28 17:15:23
 * Problem URL: https://atcoder.jp/contests/practice2/tasks/practice2_b
 * Result: AC
 * Execution Time: 815 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,q;cin >> n >> q;
    fenwick_tree<ll> fw(n);
    rep(i,n){
        int a; cin >> a;
        fw.add(i,a);
    }
    rep(i,q){
        int query; cin >> query;
        if(query == 0){
            int p,x; cin >> p >> x;
            fw.add(p,x);
        }
        else{
            int l,r; cin >> l >> r;
            cout << fw.sum(l,r) << endl;
        }
    }
    return 0;
}