/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc137/submissions/30255592
 * Submitted at: 2022-03-20 11:33:25
 * Problem URL: https://atcoder.jp/contests/arc137/tasks/arc137_b
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

int LIS(vector<int> a){
    int n = a.size();
    vector<int> ans(n,INT_MAX);
    rep(i,n){     
        auto itr = lower_bound(ans.begin(),ans.end(),a[i]);
        *itr = a[i];
    }
    return lower_bound(ans.begin(),ans.end(),INT_MAX)-ans.begin();
}

//1を増やしたい時に0000より00100100100をひっくりかえした方が1が増えるということに注意。
// => 連続した0の部分列の最長と連続した1の部分列の最長の差+1ではないことに気づく。
// => 累積和で管理。
int main() {
    int n; cin >> n;
    vector<int> a(n),s(n+1,0);
    rep(i,n)cin >> a[i];
    rep(i,n){
        s[i+1] += s[i];
        if(a[i] == 0)s[i+1]--;
        else s[i+1]++;
    }

    int ans1 = LIS(s);
    reverse(s.begin(),s.end());
    int ans2 = LIS(s);
    cout << ans1 + ans2 - 1 << endl;

    return 0;
}