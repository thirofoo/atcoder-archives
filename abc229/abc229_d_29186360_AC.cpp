/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc229/submissions/29186360
 * Submitted at: 2022-02-09 23:53:02
 * Problem URL: https://atcoder.jp/contests/abc229/tasks/abc229_d
 * Result: AC
 * Execution Time: 15 ms
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
    rep(i,n){
        if(s[i] == '.')cnt[i+1] = cnt[i] + 1;
        else cnt[i+1] = cnt[i];
    }
    // rep(i,n+1)cout << cnt[i] << " ";
    // cout << endl;
    int right = 0;
    for(int left=0;left<n;left++){
        //二つ目は「leftからrightまでで'.'がk子以内なら」という条件
        while(right+1 <= n && cnt[right+1]-cnt[left] <= k)right++;
        //ここに来るrightの値は初めてオーバーした時のrightになっている
        //すなわちleft=rightの時は、right-leftは空文字列を意味する。
        ans = max(ans,right-left);
        // cout << left << " " << right << " " << right-left << endl;
    }
    cout << ans << endl;
    return 0;
}