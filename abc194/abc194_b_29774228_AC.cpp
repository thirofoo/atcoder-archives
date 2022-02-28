/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc194/submissions/29774228
 * Submitted at: 2022-02-28 21:14:47
 * Problem URL: https://atcoder.jp/contests/abc194/tasks/abc194_b
 * Result: AC
 * Execution Time: 7 ms
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
    int n; cin >> n;
    vector<P> as,bs;
    rep(i,n){
        int a,b; cin >> a >> b;
        as.push_back(P(a,i));
        bs.push_back(P(b,i));
    }
    sort(as.begin(),as.end());
    sort(bs.begin(),bs.end());
    if(as[0].second != bs[0].second)cout << max(as[0].first,bs[0].first) << endl;
    else cout << min(as[0].first+bs[0].first,min(max(as[0].first,bs[1].first),max(as[1].first,bs[0].first))) << endl;
    return 0;
}