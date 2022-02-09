/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc229/submissions/29182309
 * Submitted at: 2022-02-09 20:34:54
 * Problem URL: https://atcoder.jp/contests/abc229/tasks/abc229_d
 * Result: WA
 * Execution Time: 16 ms
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
    string s; cin >> s;
    int k,ans = 0,n = s.size(); cin >> k;
    vector<int> cnt(n+1,0);
    cnt[0] = 0;
    for(int i=1;i<=n;i++){
        cnt[i] = cnt[i-1];
        if(s[i-1] == '.')cnt[i]++;
    }
    // rep(i,n+1)cout << cnt[i] << " ";
    // cout << endl;
    int right = 0;
    for(int left=0;left<n;left++){
        while(right+1 < n && cnt[right+1+1]-cnt[left] <= k){
            right++;
        }
        ans = max(ans,right-left+1);
        // cout << left << " " << right << " " << right-left << endl;
    }
    cout << ans << endl;
    return 0;
}