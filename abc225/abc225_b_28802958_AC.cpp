/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc225/submissions/28802958
 * Submitted at: 2022-01-26 11:16:12
 * Problem URL: https://atcoder.jp/contests/abc225/tasks/abc225_b
 * Result: AC
 * Execution Time: 85 ms
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
    int n,count = 0; cin >> n;
    bool frag = false;
    map<int,int> vertex;
    rep(i,n-1){
        int a,b; cin >> a >> b;
        vertex[a]++;
        vertex[b]++;
    }
    for(auto k:vertex){
        if(k.second == 1)count++;
        else if(k.second == n-1)frag = true;
    }
    if(count == n-1 && frag)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}