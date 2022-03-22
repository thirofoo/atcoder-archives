/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc136/submissions/30353911
 * Submitted at: 2022-03-22 23:51:39
 * Problem URL: https://atcoder.jp/contests/arc136/tasks/arc136_b
 * Result: RE
 * Execution Time: 114 ms
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
    vector<int> a(n),b(n);
    vector<int> vary_a(n,0),vary_b(n,0);
    rep(i,n){
        cin >> a[i];
        vary_a[a[i]]++;
    }
    rep(i,n){
        cin >> b[i];
        vary_b[b[i]]++;
    }
    if(vary_a != vary_b)return cout << "No" << endl,0;
    rep(i,n)if(vary_a[i] >= 2)return cout << "Yes" << endl,0;

    int tento1 = 0,tento2 = 0;
    fenwick_tree<int> fw1(5005),fw2(5005);
    rep(i,n){
        fw1.add(a[i]-1,1);
        tento1 += fw1.sum(a[i],5000);
    }
    rep(i,n){
        fw2.add(b[i]-1,1);
        tento2 += fw2.sum(b[i],5000);
    }

    if(tento1%2 == tento2%2)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}