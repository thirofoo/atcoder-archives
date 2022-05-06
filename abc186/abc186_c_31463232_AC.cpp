/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc186/submissions/31463232
 * Submitted at: 2022-05-06 12:48:14
 * Problem URL: https://atcoder.jp/contests/abc186/tasks/abc186_c
 * Result: AC
 * Execution Time: 22 ms
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

string to8(int n){
    string ans = "";
    while(n){
        ans += '0'+n%8;
        n /= 8;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,ans = 0; cin >> n;
    for(int i=1;i<=n;i++){
        string s10 = to_string(i),s8 = to8(i);
        if(s10.find('7') == s10.npos && s8.find('7') == s8.npos)ans++;
    }
    cout << ans << endl;

    return 0;
}