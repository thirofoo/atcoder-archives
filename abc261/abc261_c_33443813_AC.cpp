/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc261/submissions/33443813
 * Submitted at: 2022-07-23 21:13:39
 * Problem URL: https://atcoder.jp/contests/abc261/tasks/abc261_c
 * Result: AC
 * Execution Time: 395 ms
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
    
    ll n; cin >> n;
    vector<string> s(n);
    rep(i,n)cin >> s[i];
    map<string,ll> cnt;
    rep(i,n){
        if(cnt[s[i]] == 0){
            cout << s[i] << endl;
        }
        else{
            cout << s[i] + "(" + to_string(cnt[s[i]]) + ")" << endl;
        }
        cnt[s[i]]++;
    }
    
    return 0;
}