/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc022/submissions/29823459
 * Submitted at: 2022-03-03 17:52:01
 * Problem URL: https://atcoder.jp/contests/arc022/tasks/arc022_2
 * Result: AC
 * Execution Time: 78 ms
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
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    map<int,bool> cnt;

    int right = 0,ans = 0;
    for(int left=0;left<n;left++){
        while(right < n && !cnt[a[right]]){
            cnt[a[right]] = true;
            right++;
        }
        ans = max(ans,right-left);
        if(right == left)right++;
        cnt[a[left]] = false;
        if(right >= n)break;
    }
    cout << ans << '\n';
    return 0;
}