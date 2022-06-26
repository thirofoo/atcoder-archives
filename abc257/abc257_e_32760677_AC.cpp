/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/32760677
 * Submitted at: 2022-06-26 10:07:07
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_e
 * Result: AC
 * Execution Time: 12 ms
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
    
    int n,mini = INT_MAX; cin >> n;
    vector<int> c(9);
    rep(i,9){
        cin >> c[i];
        mini = min(c[i],mini);
    }
    //桁数を最大化するのが大前提
    int digit = n/mini;

    //桁数最大化しつつ、余裕が出来次第9から入れられるかを確認
    string ans = "";
    rep(i,digit){
        for(int j=8;j>=0;j--){
            if(mini*(digit-i-1) + c[j] <= n){
                n -= c[j];
                ans += '0'+j+1;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}