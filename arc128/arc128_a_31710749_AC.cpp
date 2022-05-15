/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc128/submissions/31710749
 * Submitted at: 2022-05-15 17:20:56
 * Problem URL: https://atcoder.jp/contests/arc128/tasks/arc128_a
 * Result: AC
 * Execution Time: 41 ms
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
    
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];

    ll au = 1,ag = 0;
    bool flag = true;
    rep(i,n){
        //増加部分列の場合
        if(flag){
            if(i == n-1)cout << 0 << " ";
            else if(a[i+1] >= a[i])cout << 0 << " ";
            else{
                cout << 1 << " ";
                flag = false;
            }
        }
        //減少部分列の場合
        else{
            if(i == n-1)cout << 1 << " ";
            else if(a[i+1] <= a[i])cout << 0 << " ";
            else{
                cout << 1 << " ";
                flag = true;
            }
        }
    }
    cout << endl;
    return 0;
}