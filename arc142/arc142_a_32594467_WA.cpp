/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc142/submissions/32594467
 * Submitted at: 2022-06-19 21:19:12
 * Problem URL: https://atcoder.jp/contests/arc142/tasks/arc142_a
 * Result: WA
 * Execution Time: 8 ms
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
    
    ll n,ans = 0; string k,k2,add = ""; cin >> n >> k;
    k2 = k;
    reverse(k2.begin(),k2.end());
    bool flag = (k == k2),flag2 = (k.back() == '0'),f1 = false,f2 = false;
    while(true){
        if(stoll(k+add) > n)f1 = true;
        // cout << k+add << " ";
        if(!f1)ans++;
        if(stoll(k2+add) > n)f2 = true;
        // cout << k2+add << endl;
        if(!f2 && !flag && !flag2)ans++;

        if(f1 || f2)break;
        add += '0';
    }   
    cout << ans << endl;

    return 0;
}