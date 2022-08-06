/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc263/submissions/33803258
 * Submitted at: 2022-08-06 21:03:17
 * Problem URL: https://atcoder.jp/contests/abc263/tasks/abc263_a
 * Result: AC
 * Execution Time: 6 ms
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
    
    int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
    map<int,int> cnt;
    cnt[a]++;
    cnt[b]++;
    cnt[c]++;
    cnt[d]++;
    cnt[e]++;
    if((cnt[a] == 3 || cnt[a] == 2) && (cnt[b] == 3 || cnt[b] == 2) && (cnt[c] == 3 || cnt[c] == 2) && (cnt[d] == 3 || cnt[d] == 2) && (cnt[e] == 3 || cnt[e] == 2))cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}