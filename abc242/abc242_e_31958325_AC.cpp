/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc242/submissions/31958325
 * Submitted at: 2022-05-26 13:44:29
 * Problem URL: https://atcoder.jp/contests/abc242/tasks/abc242_e
 * Result: AC
 * Execution Time: 450 ms
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

int mod = 998244353;

int main() {
    int t; cin >> t;
    rep(i,t){
        int n; string s; cin >> n >> s;
        ll mid = (n+1)/2,tmp = 0;

        rep(j,mid){
            tmp *= 26;
            tmp += s[j] - 'A';
            tmp %= mod;
        }
        tmp++; tmp %= mod;

        bool frag = false;
        for(int j=mid;j<n;j++){
            if(s[j] == s[n-1-j])continue;
            else if(s[j] >= s[n-1-j])break;
            frag = true; break;
        }
        if(frag){
            //tmpが0の時のためにmodを足して1周先を考えている。
            tmp += mod-1;
            tmp %= mod;
        }
        cout << tmp << '\n';
    }
    return 0;
}