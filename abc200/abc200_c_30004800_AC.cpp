/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc200/submissions/30004800
 * Submitted at: 2022-03-11 19:31:54
 * Problem URL: https://atcoder.jp/contests/abc200/tasks/abc200_c
 * Result: AC
 * Execution Time: 73 ms
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
    map<ll,ll> ans;
    rep(i,n){
        int a; cin >> a;
        ans[a%200]++;
    }

    ll answer = 0;
    rep(i,200){
        answer += ans[i]*(ans[i]-1)/2;
    }
    cout << answer << endl;
    return 0;
}