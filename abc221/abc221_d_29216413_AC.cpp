/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc221/submissions/29216413
 * Submitted at: 2022-02-11 17:32:41
 * Problem URL: https://atcoder.jp/contests/abc221/tasks/abc221_d
 * Result: AC
 * Execution Time: 165 ms
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
    //解説AC
    //日付とかの時間が関係するときはタイムスリップとかが無ければ日付の浅い順に貪欲法的に解ける時もある。
    int n,cnt = 0; cin >> n;
    vector<P> day;
    vector<int> ans(n+1);
    rep(i,n){
        int a,b; cin >> a >> b;
        day.push_back(P(a,1));
        day.push_back(P(a+b,-1));
    }
    sort(day.begin(),day.end());
    rep(i,day.size()-1){
        cnt += day[i].second;
        //次の日に行くならcnt分だけインクリメント
        ans[cnt] += day[i+1].first-day[i].first;
    }
    for(int i=1;i<=n;i++)cout << ans[i] << " ";
    cout << endl;
    return 0;
}