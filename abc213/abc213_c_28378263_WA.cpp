/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/28378263
 * Submitted at: 2022-01-08 20:25:42
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_c
 * Result: WA
 * Execution Time: 219 ms
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
    int h,w,n; cin >> h >> w >> n;
    vector<tuple<int,int,int>> card;
    rep(i,n){
        int a,b; cin >> a >> b;
        card.push_back(tuple<int,int,int>(a,b,i+1));
    }
    sort(card.begin(),card.end());
    rep(i,n)cout << get<2>(card[i]) << " " << i+1 << endl;
    return 0;
}